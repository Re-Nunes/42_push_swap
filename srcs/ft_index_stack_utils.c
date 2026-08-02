/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_stack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:02:50 by renatanu          #+#    #+#             */
/*   Updated: 2026/08/01 18:02:51 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_index_stack(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		count;

	if (!a || !a->head)
		return ;
	current = a->head;
	while (current)
	{
		count = 0;
		compare = a->head;
		while (compare)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}