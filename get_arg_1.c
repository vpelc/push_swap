/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:53:21 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/17 17:17:08 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_get_arg(char *str, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node) * 1);
	new_node->data = ft_atol(str);
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

t_node	*ft_lstlast(t_node *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void	ft_lstadd_back(t_node **list, t_node *new)
{
	if (list && *list && new)
		ft_lstlast(*list)->next = new;
	else
		*list = new;
}
