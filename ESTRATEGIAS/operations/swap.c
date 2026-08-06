// sa: Troca os elementos da pilha a.

// sb: Troca os elementos da pilha b.

// ss: Executa sa e sb ao mesmo tempo.

#include "operations.h"

void	ft_sa(t_stack **a, t_config *config)
{
	do_swap(a);
	if (!config->has_bench)
		ft_printf("sa\n");
	config->ops.sa++;
	config->ops.total++;
}

void	ft_sb(t_stack **b, t_config *config)
{
	do_swap(b);
	if (!config->has_bench)
		ft_printf("sb\n");
	config->ops.sb++;
	config->ops.total++;
}

void	ft_ss(t_stack **a, t_stack **b, t_config *config)
{
	do_swap(a);
	do_swap(b);
	if (!config->has_bench)
		ft_printf("ss\n");
	config->ops.ss++;
	config->ops.total++;
}

static void	do_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
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