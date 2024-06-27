/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:30:50 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/27 20:20:41 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(void)
{
	unsigned int	n;

	n = 1;
	while (n <= 100)
	{
		if ((n >= 1 && n < 10) && (n % 3 != 0) && (n % 5 != 0))
			ft_putchar(n + '0');
		else if (n % 15 == 0)
			ft_putstr("fizzbuzz");
		else if (n % 3 == 0)
			ft_putstr("fizz");
		else if (n % 5 == 0)
			ft_putstr("buzz");
		else
		{
			ft_putchar((n / 10) + '0');
			ft_putchar((n % 10) + '0');
		}
		ft_putchar('\n');
		n++;
	}
	return (0);
}
