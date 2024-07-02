/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:09:49 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/02 16:52:41 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				swapped;

	if (size < 2)
		return ;
	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}

}

/*
#include <stdio.h>
void	print_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	tab[] = {3, 2, 5, 8, 4, 3, 1};
	unsigned int	size = sizeof(tab) / sizeof(tab[0]);

	printf("Original array: \n");
	print_int_tab(tab, size);

	sort_int_tab(tab, size);
	printf("Sorted array: \n");
	print_int_tab(tab, size);
	return (0);
}
*/
