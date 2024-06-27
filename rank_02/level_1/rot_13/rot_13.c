/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:18:10 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/27 21:35:53 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rot_13(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm')
			|| (str[i] >= 'A' && str[i] <= 'M'))
			ft_putchar(str[i] + 13);
		else if ((str[i] >= 'n' && str[i] <= 'z')
			|| (str[i] >= 'N' && str[i] <= 'Z'))
			ft_putchar(str[i] - 13);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		rot_13(argv[1]);
	write (1, "\n", 1);
	return (0);
}
