/* srcs/algorithms/radix_sort.c */
#include "../../includes/push_swap.h"

static int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static int	ft_get_max_bits(t_stack *a)
{
	int		max;
	int		max_bits;
	t_stack	*tmp;

	if (!a)
		return (0);
	max = a->value;
	tmp = a->next;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix_sort(t_stack **a, t_stack **b, t_config *config)
{
	int	bit;
	int	size;
	int	i;
	int	max_bits;

	max_bits = ft_get_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		size = ft_stack_size(*a);
		i = 0;
		while (i < size)
		{
			if ((((*a)->value >> bit) & 1) == 0)
				ft_pb(a, b, config);
			else
				ft_ra(a, config);
			i++;
		}
		while (*b)
			ft_pa(a, b, config);
		bit++;
	}
}
