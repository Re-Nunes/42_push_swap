//rra: Roda reversa na pilha a.

//rrb: Roda reversa na pilha b.

//rrr: Executa rra e rrb ao mesmo tempo.

#include "operations.h"

void    ft_rra(t_stack **a, t_config *config)
{
    do_reverse_rotate(a);
    if (!config->has_bench)
        ft_printf("rra\n");
    config->ops.rra++;
    config->ops.total++;
}

void    ft_rrb(t_stack **b, t_config *config)
{
    do_reverse_rotate(b);
    if (!config->has_bench)
        ft_printf("rrb\n");
    config->ops.rrb++;
    config->ops.total++;
}

void    ft_rrr(t_stack **a, t_stack **b, t_config *config)
{
    do_reverse_rotate(a);
    do_reverse_rotate(b);
    if (!config->has_bench)
        ft_printf("rrr\n");
    config->ops.rrr++;
    config->ops.total++;
}

static void do_reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *penultimate;

    if (!stack || !*stack || !(*stack)->next)
        return ;

    penultimate = NULL;
    last = *stack;
    
    // Pega o ultimo e o penultimo
    while (last->next)
    {
        penultimate = last;
        last = last->next;
    }

    // desconecta o ultimo do penúltimo
    penultimate->next = NULL;

    // leva ultimo no topo
    last->next = *stack;
    (*stack)->prev = last;
    last->prev = NULL;
    
    // atualiza o topo da pilha
    *stack = last;
}