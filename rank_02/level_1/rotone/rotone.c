/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:39:05 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/27 21:46:31 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] < 'z')
			|| (str[i] >= 'A' && str[i] < 'Z'))
			ft_putchar(str[i] + 1);
		else if (str[i] == 'z' || str[i] == 'Z')
			ft_putchar(str[i] - 25);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
