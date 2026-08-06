/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:51:28 by renatanu          #+#    #+#             */
/*   Updated: 2026/06/21 17:48:23 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;
	t_list	*lst_next;

	if (!lst || !*lst || !del)
		return ;
	last = *lst;
	while (last)
	{
		lst_next = last->next;
		ft_lstdelone(last, del);
		last = lst_next;
	}
	*lst = NULL;
}
