/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:06:02 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/22 18:46:12 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Calculates the smallest amount of operations nedded
	amongst the sort cases
*/
int	get_min_operation(t_node *stack_a, t_node *stack_b)
{
	int		i;
	t_node	*tmp;

	tmp = stack_a;
	i = case_rarb(stack_a, stack_b, stack_a->data);
	while (tmp)
	{
		if (i > case_rarb(stack_a, stack_b, tmp->data))
			i = case_rarb(stack_a, stack_b, tmp->data);
		if (i > case_rrarrb(stack_a, stack_b, tmp->data))
			i = case_rrarrb(stack_a, stack_b, tmp->data);
		if (i > case_rrarb(stack_a, stack_b, tmp->data))
			i = case_rrarb(stack_a, stack_b, tmp->data);
		if (i > case_rarrb(stack_a, stack_b, tmp->data))
			i = case_rarrb(stack_a, stack_b, tmp->data);
		tmp = tmp->next;
	}
	return (i);
}

/*	Loops until there is only 3 numbers in stack A
	Gets the samllest amount operations possible with the
	function get_min_operation but sill needs to find the
	good case
	When it finds it, does the sort it found
*/
void	sort_b(t_node **stack_a, t_node **stack_b)
{
	int		i;
	t_node	*tmp;

	while (count_node(stack_a) > 3 && !check_sort(*stack_a))
	{
		tmp = *stack_a;
		i = get_min_operation(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb(*stack_a, *stack_b, tmp->data))
			{
				do_rarb(stack_a, stack_b, tmp->data);
				i = -1;
			}
			else if (i == case_rrarrb(*stack_a, *stack_b, tmp->data))
			{
				do_rrarrb(stack_a, stack_b, tmp->data);
				i = -1;
			}
			else if (i == case_rarrb(*stack_a, *stack_b, tmp->data))
			{
				do_rarrb(stack_a, stack_b, tmp->data);
				i = -1;
			}
			else if (i == case_rrarb(*stack_a, *stack_b, tmp->data))
			{
				do_rrarb(stack_a, stack_b, tmp->data);
				i = -1;
			}
			else
				tmp = tmp->next;
		}
	}
}

void	sort_a(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	min;

	while (count_node(stack_b) > 0)
	{
		if ((ft_lstlast(*stack_a))->data > (*stack_b)->data)
			rra(stack_a);
		pa(stack_a, stack_b);
	}
	min = get_min(*stack_a);
	i = get_index(*stack_a, min);
	if (i < count_node(stack_a) - 1)
	{
		while ((*stack_a)->data != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->data != min)
			rra(stack_a);
	}
}

/*	1. pushes 2 numbers no matter what
	2. pushes while in descending order 
	(the stack has to be visualized as loop so it might
	not be sorted from top to bottom but from max to bottom
	then link bottom to top then from top to min, min is
	supposed to be above max if it isnt on the bottom)
	3. sorts a by fistly sorting the 3 numbers left
	4. pushing from stack B to stack A in sorted way*/
void	sort(t_node **stack_a, t_node **stack_b)
{
	if (count_node(stack_a) > 3)
		pb(stack_b, stack_a);
	if (count_node(stack_a) > 3)
		pb(stack_b, stack_a);
	if (count_node(stack_a) > 3)
		sort_b(stack_a, stack_b);
	sort3(stack_a);
	sort_a(stack_a, stack_b);
}
