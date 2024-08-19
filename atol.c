/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:38:34 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/18 19:19:20 by vpelc            ###   ########.fr       */
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
	if (!ft_isdigit(str[i]))
		return (2147483648);
	while (ft_isdigit(str[i]))
	{
		r = r * 10;
		r = r + (str[i] - 48);
		i++;
	}
	if (!ft_isdigit(str[i]) && str[i] != '\0')
		return (2147483648);
	return (r * n);
}
