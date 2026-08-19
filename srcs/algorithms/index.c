/* srcs/algorithms/index.c */
#include "../../includes/push_swap.h"

void	ft_index_stack(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;
	int		count;

	if (!a)
		return ;
	current = a;
	while (current)
	{
		count = 0;
		compare = a;
		while (compare)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->value = count;
		current = current->next;
	}
}
