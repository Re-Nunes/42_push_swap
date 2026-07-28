/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:12:34 by renatanu          #+#    #+#             */
/*   Updated: 2026/07/28 17:56:16 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

int	ft_stack_add_top(t_stack *stack, int nb)
{
	int *content;
	t_list *link_node;
	t_list *temp;
	
	content = malloc(sizeof(*content));
	if (content == NULL)
		return (0);
	*content = nb;
	link_node = ft_lstnew(content);
	if (link_node == NULL)
	{
		free(content);
		return (0);
	}
	temp = stack->head;
	stack->head = link_node;
	link_node->next = temp;
	return (1);
}

ft_stack_add_bottom(t_stack *stack, int nb)
{
	int *content;
	t_list *link_node;
	t_list *temp;
	
	content = malloc(sizeof(*content));
	if (content == NULL)
		return (0);
	*content = nb;
	link_node = ft_lstnew(content);
	if (link_node == NULL)
	{
		free(content);
		return (0);
	}
	
}

void	*ft_stack_clear(t_stack *stack)
{
	
}

t_stack *ft_stacknew(void)
{

t_stack *stack;

stack = malloc(sizeof(t_stack));
if (!stack)
	return (NULL);
stack->head = NULL;
stack->size = 0;
return (stack);

}