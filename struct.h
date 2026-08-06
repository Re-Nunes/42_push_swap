#ifndef STRUCT_H
# define STRUCT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
    t_node  *head;
    t_node  *tail;
    int     size;
}   t_stack; 

typedef struct s_config
{
	int			has_strategy; // int has_strategy;: Indica se o programa recebeu ou deve usar alguma estratégia específica de ordenação/execução.
	int			has_bench; // int has_bench;: Usado para ativar um modo de teste de desempenho (benchmark), para medir o número de operações ou tempo de execução.
	int			has_numbers; // int has_numbers;: Indica se os números a serem ordenados já foram passados 
	int			has_after_numbers; // int has_after_numbers;: Usado para controlar ou validar se há algum parâmetro extra ou indesejado após os números, ou alguma configuração pós-leitura.
	double		initial_disorder;
	t_ops		ops;
	t_strategy	strategy_type;
}		t_config;

// Protótipos de funções (exemplo)
void    ft_init_stack(t_stack *stack);
void    ft_add_node(t_stack *stack, int value);

void    init_config(t_config *config);
int     parse_config(int argc, char **argv, t_config *config);

#endif
