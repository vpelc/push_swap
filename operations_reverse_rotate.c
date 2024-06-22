/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:16:02 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/20 14:03:27 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a)
{
	ft_rotate_reverse(stack_a);
	printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	ft_rotate_reverse(stack_b);
	printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate_reverse(stack_a);
	ft_rotate_reverse(stack_b);
	printf("rrr\n");
}
