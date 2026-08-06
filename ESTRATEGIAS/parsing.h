#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
#include "../struct.h"
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


long	ft_atol(const char *str);
int		is_numeric(const char *str);
int		has_overflow(long value);
void	free_split(char **split);
void	init_config(t_config *config);
int		parse_arguments(int argc, char *argv[], t_stack **a, t_config *config);

#endif
