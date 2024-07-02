/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:07 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/02 16:05:27 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isnumeric(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	fprime(int n)
{
	int	is_first_factor = 1;
	int	factor = 2;

	if (n == 1)
	{
		printf("1");
		return ;
	}
	while (n > 1)
	{
		while (n % factor == 0)
		{
			if (!is_first_factor)
				printf("*");
			printf("%d", factor);
			n /= factor;
			is_first_factor = 0;
		}
		factor++;
	}

}

int	main(int argc, char *argv[])
{
	int	num;

	if (argc == 2)
	{
		if (!ft_isnumeric(argv[1]))
		{
			printf("\n");
			return (1);
		}
		num = atoi(argv[1]);
		if (num > 0)
			fprime(num);
	}
	printf("\n");
	return (0);
}
