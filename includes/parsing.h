#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# include "libft.h"

typedef enum e_strategy
{
	STRAT_ADAPTIVE = 1,
	STRAT_SIMPLE, //2
	STRAT_MEDIUM, //3
	STRAT_COMPLEX,//4
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
} t_config;

int parse_flags(char *arg);
int	ft_parse_atoi(char *arg);

#endif