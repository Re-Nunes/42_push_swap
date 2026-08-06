#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../libft/libft.h"
# include "../../struct.h"
# include "../parsing.h"

void	ft_sa(t_stack *a, t_config *config);
void	ft_sb(t_stack *b, t_config *config);
void	ft_ss(t_stack *a, t_stack *b, t_config *config);
void	ft_pa(t_stack *a, t_stack *b, t_config *config);
void	ft_pb(t_stack *a, t_stack *b, t_config *config);
void	ft_ra(t_stack *a, t_config *config);
void	ft_rb(t_stack *b, t_config *config);
void	ft_rr(t_stack *a, t_stack *b, t_config *config);
void	ft_rra(t_stack *a, t_config *config);
void	ft_rrb(t_stack *b, t_config *config);
void	ft_rrr(t_stack *a, t_stack *b, t_config *config);

#endif

/*
sa (Swap A)
Nome completo: Swap A
Descrição: Troca os dois primeiros elementos do topo da pilha a. Se houver apenas um elemento ou nenhum, a função não faz nada.


sb (Swap B)
Nome completo: Swap B
Descrição: Troca os dois primeiros elementos do topo da pilha b. Se houver apenas um elemento ou nenhum, nada acontece.


ss (Swap Both)
Nome completo: Swap SS (sa e sb simultâneos)
Descrição: Executa um sa e um sb ao mesmo tempo, trocando os dois primeiros elementos da pilha a e os dois primeiros da pilha b.


pa (Push A)
Nome completo: Push A
Descrição: Pega o primeiro elemento do topo da pilha b e o coloca no topo da pilha a. Se a pilha b estiver vazia, não faz nada.

pb (Push B)
Nome completo: Push B
Descrição: Pega o primeiro elemento do topo da pilha a e o coloca no topo da pilha b. Se a pilha a estiver vazia, não faz nada.


ra (Rotate A)
Nome completo: Rotate A
Descrição: Desloca todos os elementos da pilha a uma posição para cima. O primeiro elemento (topo) passa a ser o último da pilha.


rb (Rotate B)
Nome completo: Rotate B
Descrição: Desloca todos os elementos da pilha b uma posição para cima. O primeiro elemento (topo) passa a ser o último da pilha.


rra (Reverse Rotate A)
Nome completo: Reverse Rotate A
Descrição: Desloca todos os elementos da pilha a uma posição para baixo. O último elemento da pilha passa a ser o primeiro (topo).


rrb (Reverse Rotate B)
Nome completo: Reverse Rotate B
Descrição: Desloca todos os elementos da pilha b uma posição para baixo. O último elemento da pilha passa a ser o primeiro (topo).


rrr (Reverse Rotate Both)
Nome completo: Reverse Rotate RR (rra e rrb simultâneos)
Descrição: Executa um rra e um rrb ao mesmo tempo, fazendo a rotação reversa nas duas pilhas simultaneamente.



*/