/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases_do.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:36:34 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/22 18:39:20 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Sorts the stacks with only rotate to put the number in
	the correct position in stack B
	Firtly it puts the number on top of stack A and sorts 
	stack B with rr
	Then if still needed continue to put the number on top
	of stack A with ra OR continue to sort stack B with rb
	Lastly it pushes the number from stack A to stack B		
*/
void	do_rarb(t_node **stack_a, t_node **stack_b, int data)
{
	int	i;

	i = pos_stack(*stack_b, data);
	while ((*stack_a)->data != data && i > 0)
	{
		rr(stack_a, stack_b);
		i--;
	}
	while ((*stack_a)->data != data)
		ra(stack_a);
	while (i > 0)
	{
		rb(stack_b);
		i--;
	}
	pb(stack_b, stack_a);
}

/*	Sorts the stacks with only reverse rotate to put the number
	in the correct position in stack B
	Firtly it puts the number on top of stack A and sorts 
	stack B with rrr
	Then if still needed continue to put the number on top
	of stack A  with rra OR continue to sort stack B with rrb 		
	Lastly it pushes the number from stack A to stack B			
*/
void	do_rrarrb(t_node **stack_a, t_node **stack_b, int data)
{
	int	i;

	i = pos_stack(*stack_b, data);
	while ((*stack_a)->data != data && i > count_node(stack_b))
	{
		rrr(stack_a, stack_b);
		i++;
	}
	while ((*stack_a)->data != data)
		rra(stack_a);
	while (i > count_node(stack_b))
	{
		rrb(stack_b);
		i++;
	}
	pb(stack_b, stack_a);
}

/*	Sorts the stacks with reverse rotate in stack A 
	to put the number on top and rotate in stack B
	to sort it so the number is in the correct position
	It puts the number on top of stack A first then 
	it sorts the stack B
	Lastly it pushes the number from stack A to stack B		
*/
void	do_rrarb(t_node **stack_a, t_node **stack_b, int data)
{
	int	i;

	i = pos_stack(*stack_b, data);
	while ((*stack_a)->data != data)
		rra(stack_a);
	while (i > 0)
	{
		rb(stack_b);
		i--;
	}
	pb(stack_b, stack_a);
}

/*	Sorts the stacks with rotate in stack A to put
	the number on top and reverse rotate in stack B
	to sort it so the number is in the correct position
	It puts the number on top of stack A first then 
	it sorts the stack B
	Lastly it pushes the number from stack A to stack B	
*/
void	do_rarrb(t_node **stack_a, t_node **stack_b, int data)
{
	int	i;

	i = pos_stack(*stack_b, data);
	while ((*stack_a)->data != data)
		ra(stack_a);
	while (i > count_node(stack_b))
	{
		rrb(stack_b);
		i++;
	}
	pb(stack_b, stack_a);
}
