/* srcs/algorithms/compute_disorder.c */
#include "../../includes/push_swap.h"

static void	ft_count_mistakes(t_stack *current, int *mistakes, int *total)
{
	t_stack	*runner;

	runner = current->next;
	while (runner != NULL)
	{
		(*total)++;
		if (current->value > runner->value)
			(*mistakes)++;
		runner = runner->next;
	}
}

double	compute_disorder(t_stack *a)
{
	t_stack	*current;
	int		mistakes;
	int		total;

	if (!a || !a->next)
		return (0.0);
	mistakes = 0;
	total = 0;
	current = a;
	while (current != NULL)
	{
		ft_count_mistakes(current, &mistakes, &total);
		current = current->next;
	}
	if (total == 0)
	{
		return (0.0);
	}
	return ((double)mistakes / total);
}