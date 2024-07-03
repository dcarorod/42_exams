/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:56:43 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/03 14:26:45 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		if (f)
			f(current->data);
		current = current->next;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

static t_list	*create_node(void *data)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

static void	print_data(void *data)
{
	printf("%s\n", (char *)data);
}

static void	free_list(t_list *lst)
{
	t_list	*current;
	t_list	*next_node;

	current = lst;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

int	main(void)
{
	t_list	*node1 = create_node("Node 1");
	t_list	*node2 = create_node("Node 2");
	t_list	*node3 = create_node("Node 3");

	if (node1)
		node1->next = node2;
	if (node2)
		node2->next = node3;

	printf("\nForeach applied:\n");
	ft_list_foreach(node1, print_data);
	printf("\n");
	free_list(node1);
	return (0);
}
*/
