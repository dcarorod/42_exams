/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:05:37 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/05 15:42:08 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*previous = NULL;
	t_list	*current;
	t_list	*temp;

	current = *begin_list;

	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			temp = current;
			if (previous)
				previous->next = current->next;
			else
				*begin_list = current->next;
			current = current->next;
			free(temp);
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}

}


/*void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*temp;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
	}
	current = *begin_list;
	while (current && current->next)
	{
		if ((*cmp)(current->next->data, data_ref) == 0)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
		}
		else
			current = current->next;
	}
}

*/
