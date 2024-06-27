/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:45:13 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/27 19:25:58 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_error(void)
{
	printf("Error\n");
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
	if (argc == 2)
		return (send_error(), 0);
	stack_a = put_arg(argv[i], i, &error);
	if (error == 1)
		return (send_error(), 0);
	i++;
	while (i < argc)
	{
		tmp = put_arg(argv[i], i, &error);
		if (error == 1)
			return (send_error(), 0);
		ft_lstadd_back(&stack_a, tmp);
		i++;
	}
	sort(&stack_a, &stack_b);
	return (0);
}
/* 	tmp = stack_a;
	while (tmp)
	{
		printf("%ld : %ld\n", tmp->index, tmp->data);
		tmp = tmp->next;
	}
	printf("\nNow\n\n");
	
	tmp = stack_a;
	printf("\n");
	while (tmp)
	{
		printf("%ld : %ld\n", tmp->index, tmp->data);
		tmp = tmp->next;
	}
	tmp = stack_b;
	printf("\n");
	while (tmp)
	{
		printf("%ld : %ld\n", tmp->index, tmp->data);
		tmp = tmp->next;
	}
	 */