/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:26:51 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/22 18:49:32 by vpelc            ###   ########.fr       */
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

void	ft_push(t_node **list_a, t_node **list_b)
{
	t_node	*temp;
	long	i;

	if (!(*list_b))
		return ;
	temp = *list_b;
	*list_b = temp->next;
	temp->next = *list_a;
	*list_a = temp;
	temp->index = 1;
	while (temp)
	{
		i = temp->index;
		i--;
		temp->index = i;
		temp = temp->next;
	}
}

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


