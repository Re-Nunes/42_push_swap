#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// Estrutura para os nós da pilha
typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;

// Estrutura para configurar o estado do programa
typedef struct s_config
{
    int     has_bench;
    int     strategy; // 0=Simple, 1=Medium, 2=Complex, 3=Adaptive
    struct {
        int sa; int sb; int ss;
        int pa; int pb;
        int ra; int rb; int rr;
        int rra; int rrb; int rrr;
        int total;
    } ops;
}   t_config;

// --- PROTÓTIPOS DAS OPERAÇÕES DO PUSH_SWAP ---
void        ft_sa(t_stack **a, t_config *config);
void        ft_sb(t_stack **b, t_config *config);
void        ft_ss(t_stack **a, t_stack **b, t_config *config);
void        ft_pa(t_stack **a, t_stack **b, t_config *config);
void        ft_pb(t_stack **a, t_stack **b, t_config *config);
void        ft_ra(t_stack **a, t_config *config);
void        ft_rb(t_stack **b, t_config *config);
void        ft_rr(t_stack **a, t_stack **b, t_config *config);
void        ft_rra(t_stack **a, t_config *config);
void        ft_rrb(t_stack **b, t_config *config);
void        ft_rrr(t_stack **a, t_stack **b, t_config *config);

// --- PROTÓTIPOS DE PARSING, ESTRATÉGIAS E UTILITÁRIOS ---
void        ft_error_exit(t_stack **a, char **split);
void        ft_free_split(char **split);
double      compute_disorder(t_stack *a);
void        ft_index_stack(t_stack *a);
int         ft_parse_flag(char *arg, t_config *config);
long long   ft_atoll(const char *str, int *error);
int         ft_is_digit_str(char *str);
void        ft_execute_strategy(t_stack **a, t_stack **b, t_config *config);

// Protótipos básicos de pilha e nós
t_stack     *ft_create_node(int value);
void        ft_add_back(t_stack **stack, t_stack *new_node);
void        ft_free_stack(t_stack **stack);

#endif