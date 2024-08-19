/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:17:01 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/18 13:58:34 by vpelc            ###   ########.fr       */
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

/*	Finds the position in which the number needs to be */
int	pos_stack(t_node *stack, int data)
{
	int		i;
	t_node	*tmp;

	i = 1;
	if (data < ft_lstlast(stack)->data && data > stack->data)
		return (0);
	else if (data < get_min(stack) || data > get_max(stack))
		return (get_index(stack, get_max(stack)));
	else
	{
		tmp = stack->next;
		while (data > stack->data || data < tmp->data)
		{
			stack = stack->next;
			tmp = stack->next;
			i++;
		}
	}
	return (i);
}

void	max_top(t_node **stack_b)
{
	int	i;
	int	min;

	min = get_min(*stack_b);
	i = get_index(*stack_b, min);
	if (i < count_node(stack_b) - i)
	{
		while ((ft_lstlast(*stack_b))->data != min)
			rb(stack_b);
	}
	else
	{
		while (ft_lstlast((*stack_b))->data != min)
			rrb(stack_b);
	}
}
