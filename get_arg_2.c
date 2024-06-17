/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:38:34 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/15 13:05:43 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static	int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

static	int	ft_isnegative(char str)
{
	if (str == '+')
		return (1);
	if (str == '-')
		return (-1);
	return (0);
}

static	int	check_longmax(const char *str, long i)
{
	int	j;

	j = 0;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i + j]))
		j++;
	if (j > 19)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	long	r;	
	int		n;

	n = 1;
	r = 0;
	i = ft_isspace(str);
	if (ft_isnegative(str[i]) != 0)
	{
		n *= ft_isnegative(str[i]);
		i++;
	}
	if (check_longmax(str, i))
	{
		if (n == -1)
			return (0);
		return (-1);
	}
	while (ft_isdigit(str[i]))
	{
		r = r * 10;
		r = r + (str[i] - 48);
		i++;
	}
	return (r * n);
}
