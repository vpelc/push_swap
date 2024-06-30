/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:14:30 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/20 14:03:40 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **list)
{
	t_node	*temp;
	int		length;
	int		l;

	length = count_node(list);
	l = length;
	if (!(*list) || length < 1)
		return ;
	temp = *list;
	while (length > 1)
	{
		*list = (*list)->next;
		(*list)->index -= 1;
		length--;
	}
	(*list)->next = temp;
	*list = temp->next;
	temp->index = l;
	temp->next = NULL;
}

void	ra(t_node **stack_a)
{
	ft_rotate(stack_a);
	printf("ra\n");
}

void	rb(t_node **stack_b)
{
	ft_rotate(stack_b);
	printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	printf("rr\n");
}
