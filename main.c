/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:45:13 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/19 14:06:33 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (0);
}
