/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:45:13 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/23 17:52:06 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*node;
	t_node	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	node = *stack;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*stack = NULL;
}

static void	send_error(void)
{
	write(2, "Error\n", 6);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*tmp;
	int		error;
	int		i;

	i = 1;
	error = 0;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = put_arg(argv[i], i, &error);
	if (error == 1)
		return (send_error(), 0);
	while (++i < argc)
	{
		tmp = put_arg(argv[i], i, &error);
		if (error == 1)
			return (send_error(), 0);
		ft_lstadd_back(&stack_a, tmp);
	}
	if (!check_arg_repeat(&stack_a))
		return (send_error(), 0);
	sort(&stack_a, &stack_b);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
