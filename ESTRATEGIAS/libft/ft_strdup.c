/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 18:35:14 by renatanu          #+#    #+#             */
/*   Updated: 2026/06/21 14:58:59 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*ptr;
	size_t	i;

	ptr = (char *) s;
	str = malloc((ft_strlen(ptr) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
