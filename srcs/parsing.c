/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanu <renatanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:58:39 by renatanu          #+#    #+#             */
/*   Updated: 2026/07/28 16:58:08 by renatanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static my_atoi(char *arg)
{
	int nb;
	int i;
	int sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (arg[i] == ' ' || arg[i] == '\n' || arg[i] == '\r' || arg[i] == '\t' || arg[i] == '\v' || arg[i] == '\f')
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

static int isnumber(char *arg)
{
	int i;
	
	i = 0;
	while (arg[i] == ' ' || arg[i] == '\n' || arg[i] == '\r' || arg[i] == '\t' || arg[i] == '\v' || arg[i] == '\f')
		i++; 
	if ((arg[i] == '-' || arg[i] == '+') && ft_isdigit(arg[i + 1]))
		i++;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	if (arg[i] == '\0' || arg[i] == ' ' || arg[i] == '\n' || arg[i] == '\r' || arg[i] == '\t' || arg[i] == '\v' || arg[i] == '\f')
		return (1);
	return (0);
}

int ft_parse_arguments(int argc, char *argv[], t_stack *stack_a)
{
	int i;
	int nb;

	i = 0;
	while (argv[i] && isnumber(argv[i]))
	{
		nb = my_atoi(argv[i]);
		//verificar se o numero é repetido
		//adicionar na stack 
	}
}

