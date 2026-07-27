#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft/libft.h"
# include "stack.h"

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