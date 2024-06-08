/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:29:13 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/08 14:23:59 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

/* Stack structure */
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

/* Functions for the operations */
int		ft_count_node(t_node **list);
void	ft_swap(t_node **list);
void	ft_push(t_node **list_a, t_node **list_b);
void	ft_rotate(t_node **list);
void	ft_rotate_reverse(t_node **list);

/* Operations for stack A */
void	sa(t_node **stack_a);
void	pa(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rra(t_node **stack_a);

/* Operations for stack B */
void	sb(t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
void	ra(t_node **stack_b);
void	rra(t_node **stack_b);

/* Operations for both stacks */
void	ss(t_node **stack_a, t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif