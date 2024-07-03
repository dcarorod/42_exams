/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:56:25 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/03 13:26:56 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static	void	ft_swap(t_list *a, t_list *b)
{
	int	temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*current;
	t_list	*last_sorted;
	int	swapped;

	last_sorted = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = lst;
		while (current->next != last_sorted)
		{
			if (cmp(current->data, current->next->data) == 0)
			{
				ft_swap(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
		last_sorted = current;
	}
	return (lst);
}

/*
#include <stdio.h>
#include <stdlib.h>

static int	ascending(int a, int b)
{
	return (a <= b);
}

static t_list	*create_node(int data)
{
	t_list	*new_node = malloc(sizeof(t_list));

	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = 0;
	return (new_node);
}

static void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", lst->data);
		lst = lst->next;
	}
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
	// create linked list: 4 -> 2 -> 5 -> 1 -> 3
	t_list	*head;
	head = create_node(4);
	head->next = create_node(2);
	head->next->next = create_node(5);
	head->next->next->next = create_node(1);
	head->next->next->next->next = create_node(3);

	printf("Original list: ");
	print_list(head);
	printf("\n");

	sort_list(head, &ascending);
	printf("Sorted list: ");
	print_list(head);
	printf("\n");

	free_list(head);
	return (0);
}
*/
