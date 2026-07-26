/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:44:16 by renatanu          #+#    #+#             */
/*   Updated: 2026/06/11 18:00:23 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	len_size;

	if (nmemb && size > (size_t)-1 / nmemb)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr)
			ft_bzero(ptr, 1);
		return (ptr);
	}
	len_size = nmemb * size;
	ptr = malloc(len_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, len_size);
	return (ptr);
}
