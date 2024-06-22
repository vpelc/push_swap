/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:17:01 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/18 20:09:35 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_node	*stack)
{
	int	i;

	if (!stack)
		return (0);
	i = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (i > stack->data)
			i = stack->data;
		stack = stack->next;
	}
	return (i);
}

int	get_max(t_node	*stack)
{
	int	i;

	if (!stack)
		return (0);
	i = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (i < stack->data)
			i = stack->data;
		stack = stack->next;
	}
	return (i);
}

int	find_place_b(t_node *stack_b, int data)
{
	int		i;
	t_node	*tmp;

	i = 1;
	if (data < ft_lstlast(stack_b)->data && data > stack_b->data)
		return (0);
	else if (data < get_min(stack_b) || data > get_max(stack_b))
		return (get_index(stack_b, get_max(stack_b)));
	else
	{
		tmp = stack_b->next;
		while (data > stack_b->data || data < tmp->data)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	find_place_a(t_node *stack_a, int data)
{
	int		i;
	t_node	*tmp;

	i = 1;
	if (data < ft_lstlast(stack_a)->data && data > stack_a->data)
		return (0);
	else if (data < get_min(stack_a) || data > get_max(stack_a))
		return (get_index(stack_a, get_max(stack_a)));
	else
	{
		tmp = stack_a->next;
		while (data > stack_a->data || data < tmp->data)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
