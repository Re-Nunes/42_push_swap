/* srcs/parsing/error.c */
#include "../../includes/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_error_exit(t_stack **a, char **split)
{
	if (a && *a)
		ft_free_stack(a);
	if (split)
		ft_free_split(split);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
