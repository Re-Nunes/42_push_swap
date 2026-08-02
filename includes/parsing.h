#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# include "libft.h"

typedef enum e_strategy
{
	STRAT_ADAPTIVE,//0
	STRAT_SIMPLE, //1
	STRAT_MEDIUM, //2
	STRAT_COMPLEX//3
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
} t_config;

#endif