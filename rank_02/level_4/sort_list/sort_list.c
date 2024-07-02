/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:56:25 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/02 17:13:24 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	ft_swap(t_list *a, t_list *b)
{
	int	temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*current;
	int		swapped = 1;

	if (!lst)
		return (0);
	current = lst;
	while (swapped)
	{
		swapped = 0;
		while (current != 0 && current->next != 0)
		{
			if (cmp(current->data, current->next->data) == 0)
			{
				ft_swap(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
		current = lst;
	}
	return (lst);
}
