/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:16:02 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/30 17:41:41 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_reverse(t_node **list)
{
	t_node	*templist;
	t_node	*temp;
	int		length;

	length = count_node(list);
	if (!(*list) || length < 1)
		return ;
	templist = *list;
	while (templist->next->next)
		templist = templist->next;
	temp = templist->next;
	templist->next = NULL;
	temp->next = *list;
	*list = temp;
	(*list)->index = 1;
	while (length > 1)
	{
		temp = temp->next;
		temp->index += 1;
		length--;
	}
}

void	rra(t_node **stack_a)
{
	ft_rotate_reverse(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	ft_rotate_reverse(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate_reverse(stack_a);
	ft_rotate_reverse(stack_b);
	ft_printf("rrr\n");
}
