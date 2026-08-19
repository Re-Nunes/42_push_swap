/* srcs/operations/swap.c */
#include "../../includes/push_swap.h"

static void do_swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *stack = second;
}

void ft_sa(t_stack **a, t_config *config)
{
    do_swap(a);
    if (!config->has_bench)
        ft_putstr_fd("sa\n", 1);
    config->ops.sa++;
    config->ops.total++;
}

void	ft_ss(t_stack **a, t_stack **b, t_config *config)
{
	do_swap(a);
	do_swap(b);
	if (!config->has_bench)
		ft_putstr_fd("ss\n", 1);
	config->ops.ss++;
	config->ops.total++;
}

void	ft_sb(t_stack **b, t_config *config)
{
	do_swap(b);
	if (!config->has_bench)
		ft_putstr_fd("sb\n", 1);
	config->ops.sb++;
	config->ops.total++;
}
// ... adicionar sb e ss aqui (seguindo o limite de 25 linhas)