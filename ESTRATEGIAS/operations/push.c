//pa: Pega o topo de b e coloca em a.

//pb: Pega o topo de a e coloca em b.

#include "operations.h"

void	ft_pa(t_stack **a, t_stack **b, t_config *config)
{
    do_push(a, b); // destino = A, origem = B
    if (!config->has_bench)
        ft_printf("pa\n");
    config->ops.pa++;
    config->ops.total++;
}

void	ft_pb(t_stack **a, t_stack **b, t_config *config)
{
    do_push(b, a); // destino = B, origem = A
    if (!config->has_bench)
        ft_printf("pb\n");
    config->ops.pb++;
    config->ops.total++;
}

static void do_push(t_stack **dest, t_stack **src) // etapas para tirar o elemento de um pilha e por na outra 
{
    t_stack *tmp;

    if (!src || !*src)
        return ; // Se o src esta vazio nao faz nada

    tmp = *src;             // pega o elemnto do topo
    *src = (*src)->next;    // e avança para o proximo

    if (*src)
        (*src)->prev = NULL; // atualiza o novo topom

    // insere o nó no topo da pilha de destino
    tmp->next = *dest;
    if (*dest)
        (*dest)->prev = tmp;
    
    tmp->prev = NULL;
    *dest = tmp;            // destino aponta para o novo nó
}