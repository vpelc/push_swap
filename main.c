/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:45:13 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/20 13:58:39 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*tmp;
	t_node	temp;
	int		i;

	/* argc = 4;
	argv[1] = "2";
	argv[2] = "3";
	argv[3] = "1";
	//argv[4] = "8"; */
	i = 1;
	stack_a = put_arg(argv[i], i);
	i++;
	printf("\nBefore\n\n");
	while (i < argc)
	{
		tmp = put_arg(argv[i], i);
		ft_lstadd_back(&stack_a, tmp);
		i++;
	}
	tmp = stack_a;
	while (tmp)
	{
		printf("%ld : %ld\n", tmp->index, tmp->data);
		tmp = tmp->next;
	}
	printf("\nNow\n\n");
	sort3(&stack_a);
	tmp = stack_a;
	printf("\n");
	while (tmp)
	{
		printf("%ld : %ld\n", tmp->index, tmp->data);
		tmp = tmp->next;
	}
	return (0);
}