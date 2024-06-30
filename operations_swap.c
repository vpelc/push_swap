/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:02:05 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/20 14:04:02 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **list)
{
	t_node	*temp;
	t_node	*node;
	long	tmpindex;

	if (!(*list) || !((*list)->next))
		return ;
	node = *list;
	temp = node->next;
	tmpindex = node->index;
	node->next = temp->next;
	node->index = temp->index;
	temp->next = node;
	temp->index = tmpindex;
	*list = temp;
}

void	sa(t_node **stack_a)
{
	ft_swap(stack_a);
	printf("sa\n");
}

void	sb(t_node **stack_b)
{
	ft_swap(stack_b);
	printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}
