/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:29:13 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/27 18:57:05 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/* Stack structure */
typedef struct s_node
{
	long			data;
	long			index;
	struct s_node	*next;
}	t_node;

/* Functions for the operations */
int		count_node(t_node **list);
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
void	rb(t_node **stack_b);
void	rrb(t_node **stack_b);

/* Operations for both stacks */
void	ss(t_node **stack_a, t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

/*	Functions to get args and put in args
	in the stack A
*/
int		get_arg(char *str, long **tab, int *error);
t_node	*put_arg(char *str, int index, int *error);
long	ft_atol(const char *str);
char	**ft_split(char const *str, char c);

t_node	*ft_lstlast(t_node *list);
void	ft_lstadd_back(t_node **list, t_node *new);
int		check_sort(t_node *stack_a);
void	sort3(t_node **stack_a);
void	sort(t_node **stack_a, t_node **stack_b);
void	sort_b(t_node **stack_a, t_node **stack_b);
void	sort_a(t_node **stack_a, t_node **stack_b);

int		get_index(t_node *node, int data);
int		get_min(t_node	*stack);
int		get_max(t_node	*stack);

int		pos_stack(t_node *stack, int data);

int		case_rarb(t_node *stack_a, t_node *stack_b, int data);
int		case_rrarrb(t_node *stack_a, t_node *stack_b, int data);
int		case_rrarb(t_node *stack_a, t_node *stack_b, int data);
int		case_rarrb(t_node *stack_a, t_node *stack_b, int data);

void	do_rarb(t_node **stack_a, t_node **stack_b, int data);
void	do_rrarrb(t_node **stack_a, t_node **stack_b, int data);
void	do_rrarb(t_node **stack_a, t_node **stack_b, int data);
void	do_rarrb(t_node **stack_a, t_node **stack_b, int data);

int		check_arg_repeat(long **data, int length, int *error);
int		check_arg_too_big(long data, int *error);
int		check_arg_not_digit(char **str, int *error);

#endif