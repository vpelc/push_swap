/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:14:30 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/17 16:54:36 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	ft_rotate(stack_a);
	printf("ra\n");
}

void	rb(t_node **stack_b)
{
	ft_rotate(stack_b);
	printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	printf("rr\n");
}
