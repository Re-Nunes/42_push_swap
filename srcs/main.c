/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:58:48 by renatanu          #+#    #+#             */
/*   Updated: 2026/08/01 21:33:49 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "parsing.h"

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	t_config	confing;

	if (argc < 2)
		return (0);
	a = ft_stacknew();
	b = ft_stacknew();
	if (!a || !b)
		return (1);
	if (!parse_arguments(argc, argv, &a, &confing))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	if (is_stack_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	index_stack(a); // Simplifica os valores para índices (0, 1, 2...)
	execute_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
