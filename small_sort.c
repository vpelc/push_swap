/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:56:31 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/14 16:44:56 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Hardcoded sort of a list of three
	- rotate if : top = max / mid = min / bot = mid
	- reverse rotate if : top = mid / mid = max / bot = min
	- swap if : top = mid / mid = min / bot = max
	- rotate & swap if : top = max / mid = mid / bot = min
	- swap & rotate if : top = min / mid = max / bot = mid
*/
void	ft_sort3(t_node **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
		ra(stack_a);
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
		rra(stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
		sa(stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

int	ft_check_sort(t_node *stack_a)
{
	int	i;

	i = stack_a->data;
	while (stack_a)
	{
		if (i > stack_a->data)
			return (0);
		i = stack_a->data;
		stack_a = stack_a->next;
	}
	return (1);
}

