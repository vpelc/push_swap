/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:31:00 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/27 19:20:25 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg_repeat(long **data, int length, int *error)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if ((*data)[i] == (*data)[j])
			{
				return (0);
				*error = 1;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg_too_big(long data, int *error)
{
	if (data > INT_MAX || data < INT_MIN)
	{
		*error = 1;
		return (0);
	}
	return (1);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_arg_not_digit(char **str, int *error)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i] != 0)
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				*error = 1;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
