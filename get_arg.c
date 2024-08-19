/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:53:21 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/18 19:20:37 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_arg(char *str, long **tab, int *error)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ' ');
	if (!check_arg_not_digit(split, error))
		return (0);
	if (ft_strlen(split[i]) > 11)
		*error = 1;
	while (split[i])
		i++;
	*tab = malloc(sizeof(long) * i);
	i = 0;
	while (split[i])
	{
		(*tab)[i] = ft_atol(split[i]);
		if (!check_arg_too_big((*tab)[i], error))
			return (0);
		i++;
	}
	return (i);
}

t_node	*put_arg(char *str, int index, int *error)
{
	t_node	*top_node;
	t_node	*new_node;
	long	*tab;
	int		length;
	int		i;

	i = 0;
	length = get_arg(str, &tab, error);
	if (*error == 1)
		return (0);
	top_node = malloc(sizeof(t_node) * 1);
	top_node->data = tab[i];
	top_node->index = index;
	top_node->next = NULL;
	index++;
	while (++i < length)
	{
		new_node = malloc(sizeof(t_node) * 1);
		new_node->data = tab[i];
		new_node->index = index;
		new_node->next = NULL;
		ft_lstadd_back(&top_node, new_node);
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
