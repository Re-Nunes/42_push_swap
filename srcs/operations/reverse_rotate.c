/* srcs/operations/reverse_rotate.c */
#include "../../includes/push_swap.h"

static void	do_reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
}

void	ft_rra(t_stack **a, t_config *config)
{
	do_reverse_rotate(a);
	if (!config->has_bench)
		ft_putstr_fd("rra\n", 1);
	config->ops.rra++;
	config->ops.total++;
}

void	ft_rrb(t_stack **b, t_config *config)
{
	do_reverse_rotate(b);
	if (!config->has_bench)
		ft_putstr_fd("rrb\n", 1);
	config->ops.rrb++;
	config->ops.total++;
}

void	ft_rrr(t_stack **a, t_stack **b, t_config *config)
{
	do_reverse_rotate(a);
	do_reverse_rotate(b);
	if (!config->has_bench)
		ft_putstr_fd("rrr\n", 1);
	config->ops.rrr++;
	config->ops.total++;
}