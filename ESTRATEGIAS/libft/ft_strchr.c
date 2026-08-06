/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:13:25 by renatanu          #+#    #+#             */
/*   Updated: 2026/06/21 19:23:19 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	c_char;

	if (s == NULL)
		return (NULL);
	i = 0;
	str = (char *) s;
	c_char = (unsigned char) c;
	while (str[i])
	{
		if ((unsigned char)str[i] == c_char)
			return (&str[i]);
		i++;
	}
	if (c_char == '\0')
		return (&str[i]);
	return (NULL);
}
