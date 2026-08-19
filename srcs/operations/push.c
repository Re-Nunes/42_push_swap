/* srcs/operations/push.c */
#include "../../includes/push_swap.h"

static void	do_push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	tmp->prev = NULL;
	*dest = tmp;
}

void	ft_pa(t_stack **a, t_stack **b, t_config *config)
{
	do_push(a, b);
	if (!config->has_bench)
		ft_putstr_fd("pa\n", 1);
	config->ops.pa++;
	config->ops.total++;
}

void	ft_pb(t_stack **a, t_stack **b, t_config *config)
{
	do_push(b, a);
	if (!config->has_bench)
		ft_putstr_fd("pb\n", 1);
	config->ops.pb++;
	config->ops.total++;
}
