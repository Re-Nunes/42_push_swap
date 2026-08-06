/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:08:06 by renatanu          #+#    #+#             */
/*   Updated: 2026/06/11 14:08:07 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	char			*str;
	unsigned char	c_char;

	str = (char *) s;
	c_char = (unsigned char) c;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if ((unsigned char)str[len] == c_char)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
