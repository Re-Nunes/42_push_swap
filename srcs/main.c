/* srcs/main.c */
#include "../includes/push_swap.h"

void	ft_execute_strategy(t_stack **a, t_stack **b, t_config *config);
void	ft_index_stack(t_stack *a);
int		ft_parse_flag(char *arg, t_config *config);
long long	ft_atoll(const char *str, int *error);
int		ft_is_digit_str(char *str);

static void	ft_init_config(t_config *config)
{
	config->has_bench = 0;
	config->strategy = 3; // Default: Adaptive
	config->ops.sa = 0;
	config->ops.sb = 0;
	config->ops.ss = 0;
	config->ops.pa = 0;
	config->ops.pb = 0;
	config->ops.ra = 0;
	config->ops.rb = 0;
	config->ops.rr = 0;
	config->ops.rra = 0;
	config->ops.rrb = 0;
	config->ops.rrr = 0;
	config->ops.total = 0;
}

static int	ft_has_duplicates(t_stack *a)
{
	t_stack	*outer;
	t_stack	*inner;

	outer = a;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->value == inner->value)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}

static void	ft_print_bench(t_config *config, double disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	// Formatação simples para exibir a desordem em porcentagem
	ft_putnbr_fd((int)(disorder * 100), 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(config->ops.total, 2);
	ft_putstr_fd("\n", 2);
}

static t_stack	*ft_parse_args(int argc, char **argv, t_config *config)
{
	t_stack	*a;
	char	**split;
	int		i;
	int		j;
	int		error;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_parse_flag(argv[i], config))
		{
			i++;
			continue ;
		}
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			ft_error_exit(&a, split);
		j = 0;
		while (split[j])
		{
			if (!ft_is_digit_str(split[j]))
				ft_error_exit(&a, split);
			error = 0;
			ft_add_back(&a, ft_create_node((int)ft_atoll(split[j], &error)));
			if (error)
				ft_error_exit(&a, split);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	if (ft_has_duplicates(a))
		ft_error_exit(&a, NULL);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	config;
	double		disorder;

	if (argc < 2)
		return (0);
	ft_init_config(&config);
	a = ft_parse_args(argc, argv, &config);
	b = NULL;
	disorder = compute_disorder(a);
	ft_index_stack(a);
	ft_execute_strategy(&a, &b, &config);
	if (config.has_bench)
		ft_print_bench(&config, disorder);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
