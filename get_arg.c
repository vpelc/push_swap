/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:53:21 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/20 14:38:33 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_arg(char *str, long **tab)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
		i++;
	*tab = malloc(sizeof(long) * i);
	i = 0;
	while (split[i])
	{
		(*tab)[i] = ft_atol(split[i]);
		i++;
	}
	return (i);
}

t_node	*put_arg(char *str, int index)
{
	t_node	*top_node;
	t_node	*new_node;
	long	*tab;
	int		length;
	int		i;

	i = 0;
	length = get_arg(str, &tab);
	top_node = malloc(sizeof(t_node) * 1);
	top_node->data = tab[i++];
	top_node->index = index;
	top_node->next = NULL;
	index++;
	while (i < length)
	{
		new_node = malloc(sizeof(t_node) * 1);
		new_node->data = tab[i];
		new_node->index = index;
		new_node->next = NULL;
		ft_lstadd_back(&top_node, new_node);
		i++;
		index++;
	}
	return (top_node);
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
