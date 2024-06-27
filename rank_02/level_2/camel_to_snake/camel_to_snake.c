/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:47:23 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/27 23:17:43 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	camel_to_snake(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			ft_putchar('_');
		}
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		camel_to_snake(argv[1]);
	write(1, "\n", 1);
	return (0);
}
