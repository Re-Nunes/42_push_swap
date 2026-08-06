//ra: Roda a pilha a.

//rb: Roda a pilha b.

//rr: Executa ra e rb ao mesmo tempo.

#include "operations.h"
#include "../../struct.h"

void    ft_ra(t_stack **a, t_config *config)
{
    do_rotate(a);
    if (!config->has_bench)
        ft_printf("ra\n");
    config->ops.ra++;
    config->ops.total++;
}

void    ft_rb(t_stack **b, t_config *config)
{
    do_rotate(b);
    if (!config->has_bench)
        ft_printf("rb\n");
    config->ops.rb++;
    config->ops.total++;
}

void    ft_rr(t_stack **a, t_stack **b, t_config *config)
{
    do_rotate(a);
    do_rotate(b);
    if (!config->has_bench)
        ft_printf("rr\n");
    config->ops.rr++;
    config->ops.total++;
}

static void do_rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;

    first = *stack;
    
    // Pega o oltimo elemento da lista
    last = first;
    while (last->next)
        last = last->next;

    // torna o segundo elemento para o novo topo
    *stack = first->next;
    (*stack)->prev = NULL;

    // o primeiro vai para o final
    first->next = NULL;
    first->prev = last;
    last->next = first;
}