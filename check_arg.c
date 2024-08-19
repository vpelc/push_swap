/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:31:00 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/18 17:50:18 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg_repeat(t_node **stack)
{
	t_node	*tmp;
	t_node	*pmt;

	pmt = *stack;
	while (pmt)
	{
		tmp = pmt->next;
		while (tmp)
		{
			if (tmp->data == pmt->data)
				return (0);
			tmp = tmp->next;
		}
		pmt = pmt->next;
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
			if (!ft_isdigit(str[i][j])
				&& str[i][j] != '-' && str[i][j] != '+')
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
