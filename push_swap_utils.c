/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:05:22 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/18 14:46:32 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_node(t_node **list)
{
	int		i;
	t_node	*temp;

	if (!list || !(*list))
		return (0);
	temp = *list;
	i = 1;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	get_index(t_node *node, int data)
{
	int	i;

	i = 0;
	while (node->data != data)
	{
		i++;
		node = node->next;
	}
	return (i);
}
