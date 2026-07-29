#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include "stack.h"
# include <limits.h>

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_FORCED
}		t_strategy;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}		t_ops;

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

long	ft_atol(const char *str);
int		is_numeric(const char *str);
int		has_overflow(long value);
void	free_split(char **split);
void	init_config(t_config *config);
int		parse_arguments(int argc, char *argv[], t_stack **a, t_config *config);

#endif
