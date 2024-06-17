/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:06:02 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/17 17:06:21 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_node **stack_a, t_node	**stack_b)
{

}

int	ft_get_index(t_node	*node, int data)
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
