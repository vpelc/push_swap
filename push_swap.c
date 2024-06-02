/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:26:51 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/02 20:02:03 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **list)
{
	t_node	*temp;
	t_node	*node;

	if (!(*list) || !((*list)->next))
		return ;
	node = *list;
	temp = node->next;
	node->next = temp->next;
	temp->next = node;
	*list = temp;
}

void	ft_push(t_node **list_a, t_node **list_b)
{
	t_node	*temp;

	if (!(*list_b))
		return ;
	temp = *list_b;
	*list_b = temp->next;
	temp->next = *list_a;
	*list_a = temp;
}

void	ft_rotate(t_node **list)
{
	t_node	*temp;
	int		length;

	length = ft_count_node(list);
	if (!(*list) || length < 1)
		return ;
	temp = *list;
	while (length > 1)
	{
		*list = (*list)->next;
		length--;
	}
	(*list)->next = temp;
	*list = temp->next;
	temp->next = NULL;
}

int	main(int argc, char *argv[])
{
	t_node	node_a;
	t_node	node_b;
	t_node	node_c;
	t_node	*list;
	t_node	*list1;
	t_node	temp;
	t_node	temp1;

	(void)argc;
	(void)argv;

/*		**SWAP** 

	node_a.data = 4;
	node_b.data = 5;
	node_a.next = &node_b;
	node_b.next = NULL;
	list = &node_a;

	printf("\nswap\n\n");
	temp = *list;
	while (temp.next)
	{
		temp = *list;
		printf("%d\n", temp.data);
		list = temp.next;
	}

	node_a.data = 4;
	node_b.data = 5;
	node_a.next = &node_b;
	node_b.next = NULL;
	list = &node_a;
	ft_swap(&list);
	printf("\nswaped\n\n");
	temp = *list;
	while (temp.next)
	{
		temp = *list;
		printf("%d\n", temp.data);
		list = temp.next;
	} */
/*		**PUSH**

	printf("\npush\n\n");
	node_a.data = 4;
	node_b.data = 5;
	node_c.data = 3;
	node_a.next = &node_b;
	node_b.next = NULL;
	node_c.next = NULL;
	list = &node_a;
	list1 = &node_c;
	temp = *list;

	printf("pile a :\n\n");
	while (temp.next)
	{
		temp = *list;
		printf("%d\n", temp.data);
		list = temp.next;
	}



	printf("\npile b :\n\n");

	temp1 = *list1;
	printf("%d\n", temp1.data);
	list = temp1.next;

	node_a.data = 4;
	node_b.data = 5;
	node_c.data = 3;
	node_a.next = &node_b;
	node_b.next = NULL;
	node_c.next = NULL;
	list = &node_a;
	list1 = &node_c;
	ft_push(&list, &list1);
	printf("\npushed\n\n");

	temp = *list;

	printf("pile a :\n\n");
	while (temp.next)
	{
		temp = *list;
		printf("%d\n", temp.data);
		list = temp.next;
	}

	printf("\npile b :\n\n");
	printf("%s", list1);
	//temp1 = *list1;
	// printf("%d\n", temp1.data);
	// list = temp1.next; */



	node_a.data = 5;
	node_b.data = 4;
	node_c.data = 3;
	node_a.next = &node_b;
	node_b.next = &node_c;
	node_c.next = NULL;
	list = &node_a;

	printf("\nrotate\n\n");
	temp = *list;
	while (temp.next)
	{
		temp = *list;
		printf("%d\n", temp.data);
		list = temp.next;
	}

	node_a.data = 5;
	node_b.data = 3;
	node_c.data = 4;
	node_a.next = &node_b;
	node_b.next = &node_c;
	node_c.next = NULL;
	list = &node_a;
	ft_rotate(&list);
	printf("\nrotated\n\n");
	temp = *list;
	while (temp.next)
	{
		temp = *list;
		printf("%d\n", temp.data);
		list = temp.next;
	} 
	return (0);
}

