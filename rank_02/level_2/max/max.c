/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:27:54 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/28 13:35:58 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	int	max_value;

	if (len == 0)
		return (0);
	max_value = tab[0];
	for (int i = 0; i < len; i++)
	{
		if (tab[i] > max_value)
			max_value = tab[i];
	}
	return (max_value);
}
