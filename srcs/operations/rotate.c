/* srcs/operations/rotate.c */
#include "../../includes/push_swap.h"

static void	do_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ft_ra(t_stack **a, t_config *config)
{
	do_rotate(a);
	if (!config->has_bench)
		ft_putstr_fd("ra\n", 1);
	config->ops.ra++;
	config->ops.total++;
}

void	ft_rb(t_stack **b, t_config *config)
{
	do_rotate(b);
	if (!config->has_bench)
		ft_putstr_fd("rb\n", 1);
	config->ops.rb++;
	config->ops.total++;
}

void	ft_rr(t_stack **a, t_stack **b, t_config *config)
{
	do_rotate(a);
	do_rotate(b);
	if (!config->has_bench)
		ft_putstr_fd("rr\n", 1);
	config->ops.rr++;
	config->ops.total++;
}