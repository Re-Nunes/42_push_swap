/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:58:39 by renatanu          #+#    #+#             */
/*   Updated: 2026/08/06 18:12:45 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "parsing.h"

int	ft_parse_atoi(char *arg)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (ft_is_whitespace(arg[i]))
		i++;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	while (arg[i] && ft_isdigit(arg[i]))
		nb = (nb * 10) + (arg[i++] - 48);
	return (sign * nb);
}

static int	is_number(char *arg)
{
	int	i;

	i = 0;
	while (ft_is_whitespace(arg[i]))
		i++;
	if ((arg[i] == '-' || arg[i] == '+') && ft_isdigit(arg[i + 1]))
		i++;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	if (arg[i] == '\0' || ft_is_whitespace(arg[i]))
		return (1);
	return (0);
}

int	parse_arguments(int argc, char *argv[], t_stack *stack_a)
{
	int	i;
	int	nbr;

	i = 1;
	while (i < argc)
	{
		if(!parse_flags(argv[i]))
			return(0);
		if (!is_number(argv[i]))
			return (0);
		nbr = ft_parse_atoi(argv[i]);
		i++;
	}
	return (1);
}

// int	check_if_duplicate(t_stack *a)
// {
	
// }
