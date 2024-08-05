/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:10:28 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/20 14:03:14 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_node **list_a, t_node **list_b)
{
	t_node	*temp;
	//long	i;

	if (!(*list_b))
		return ;
	temp = *list_b;
	*list_b = temp->next;
	temp->next = *list_a;
	*list_a = temp;
	temp->index = 1;
	temp = temp->next;
	while (temp)
	{
		(temp->index)++;
		temp = temp->next;
	}
	temp = *list_b;
	while (temp)
	{
		(temp->index)--;
		temp = temp->next;
	}
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
	printf("pa\n");
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	ft_push(stack_b, stack_a);
	printf("pb\n");
}
