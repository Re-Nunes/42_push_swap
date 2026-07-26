/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:36:33 by renatanu          #+#    #+#             */
/*   Updated: 2026/06/04 21:16:58 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	i = 0;
	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (temp_dest < temp_src)
	{
		while (i < len)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}	
	else
	{	
		while (len-- > 0)
		{
			temp_dest[len] = temp_src[len];
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	// char	array[] = "abcdefg";
// 	char *str = NULL;
// 	//char str1[] = "ASDDF";

// 	memmove(str, str, 5);
// 	printf("Resultado: %s\n", str);

// 	//printf("%s\n", ft_memmove(str, str, 5));
// 	return (0);
// }
