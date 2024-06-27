/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:52:19 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/27 21:05:52 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_n(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}

void	repeat_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar_n(str[i], str[i] + 1 - 'a');
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar_n(str[i], str[i] + 1 - 'A');
		else
			write(1, &str[i], 1);
		i++;
	}

}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
