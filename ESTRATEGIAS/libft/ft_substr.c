/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:55:35 by renatanu          #+#    #+#             */
/*   Updated: 2026/06/21 15:09:32 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_sub;
	unsigned int	len_sub;
	unsigned int	len_s;
	unsigned int	i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	len_sub = len_s - start;
	if (len_sub > len)
		len_sub = len;
	new_sub = malloc ((len_sub + 1) * sizeof(char));
	if (!new_sub)
		return (NULL);
	i = 0;
	while (i < len_sub)
	{
	new_sub[i] = s[start + i];
		i++;
	}
	new_sub[i] = '\0';
	return (new_sub);
}
