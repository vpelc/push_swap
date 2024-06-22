/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:04:40 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/22 18:38:06 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Counts the number of operations needed to push from 
	stack A to the correct place in stack B with only rotate
	Firtly it counts the number of rr then either ra or rb
	if still needed											
*/
int	case_rarb(t_node *stack_a, t_node *stack_b, int data)
{
	int	operation;
	int	move_a;
	int	move_b;

	move_a = get_index(stack_a, data);
	move_b = pos_stack(stack_b, data);
	operation = 0;
	while (move_a > 0 && move_b > 0)
	{
		move_a--;
		move_b--;
		operation++;
	}
	while (move_a > 0)
	{
		move_a--;
		operation++;
	}
	while (move_b > 0)
	{
		move_b--;
		operation++;
	}
	return (operation);
}

/*	Counts the number of operations needed to push from 
	stack A to the correct place in stack B with only 
	reverse rotate
	Firtly it counts the number of rrr then either rra or rrb
	if still needed											
*/
int	case_rrarrb(t_node *stack_a, t_node *stack_b, int data)
{
	int	operation;
	int	move_a;
	int	move_b;

	move_a = get_index(stack_a, data);
	move_b = pos_stack(stack_b, data);
	operation = 0;
	while (move_a > count_node(&stack_a) && move_b > count_node(&stack_b))
	{
		move_a++;
		move_b++;
		operation++;
	}
	while (move_a > count_node(&stack_a))
	{
		move_a++;
		operation++;
	}
	while (move_b > count_node(&stack_b))
	{
		move_b++;
		operation++;
	}
	return (operation);
}

/*	Counts the number of operations needed to push from 
	stack A to the correct place in stack B with only 
	reverse rotate in stack A and rotate in stack B
	Firtly it counts the number of rra and then rb					
*/
int	case_rrarb(t_node *stack_a, t_node *stack_b, int data)
{
	int	operation;
	int	move_a;
	int	move_b;

	move_a = get_index(stack_a, data);
	move_b = pos_stack(stack_b, data);
	operation = 0;
	while (move_a > count_node(&stack_a))
	{
		move_a++;
		operation++;
	}
	while (move_b > 0)
	{
		move_b--;
		operation++;
	}
	return (operation);
}

/*	Counts the number of operations needed to push from 
	stack A to the correct place in stack B with only 
	rotate in stack A and reverse rotate in stack B
	Firtly it counts the number of rra and then rb					
*/
int	case_rarrb(t_node *stack_a, t_node *stack_b, int data)
{
	int	operation;
	int	move_a;
	int	move_b;

	move_a = get_index(stack_a, data);
	move_b = pos_stack(stack_b, data);
	operation = 0;
	while (move_a > 0)
	{
		move_a--;
		operation++;
	}
	while (move_b > count_node(&stack_b))
	{
		move_b++;
		operation++;
	}
	return (operation);
}
