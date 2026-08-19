/* srcs/algorithms/bucket_sort.c */
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

void	ft_bucket_sort(t_stack **a, t_stack **b, t_config *config)
{
	int	size;
	int	pushed;

	size = ft_stack_size(*a);
	pushed = 0;
	while (*a && size > 3)
	{
		if (pushed < size / 2)
		{
			ft_pb(a, b, config);
			pushed++;
		}
		else
		{
			ft_ra(a, config);
		}
	}
	while (*b)
		ft_pa(a, b, config);
}
