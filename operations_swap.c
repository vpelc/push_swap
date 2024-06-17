/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:02:05 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/17 16:54:38 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	ft_swap(stack_a);
	printf("sa\n");
}

void	sb(t_node **stack_b)
{
	ft_swap(stack_b);
	printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}
