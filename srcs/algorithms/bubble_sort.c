/* srcs/algorithms/bubble_sort.c */
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

static void	ft_rotate_back(t_stack **a, t_config *config, int count)
{
	int	k;

	k = 0;
	while (k < count)
	{
		ft_rra(a, config);
		k++;
	}
}

void	ft_bubble_sort(t_stack **a, t_stack **b, t_config *config)
{
	int	size;
	int	i;
	int	j;

	(void)b;
	size = ft_stack_size(*a);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if ((*a)->value > (*a)->next->value)
				ft_sa(a, config);
			ft_ra(a, config);
			j++;
		}
		ft_rotate_back(a, config, size - 1 - i);
		i++;
	}
}
