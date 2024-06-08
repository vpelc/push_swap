/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:10:28 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/08 14:14:04 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
