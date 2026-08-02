#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# include "libft.h"

typedef struct s_stack
{
	t_list	*head;
	int		size;
}	t_stack;


int		ft_stack_add_top(t_stack *stack, int nb);
int		ft_stack_add_bottom(t_stack *stack, int nb);
void	ft_stack_clear(t_list *node);


t_stack *ft_stack_new(void);
int		ft_is_whitespace(char c);

#endif