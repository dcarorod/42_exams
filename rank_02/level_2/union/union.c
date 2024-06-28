/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:37:01 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/28 14:13:58 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_present(char *str, char c, int pos)
{
	for (int i = 0; i < pos; i++)
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (s1[i])
	{
		c = s1[i];
		if (!is_present(s1, c, i))
			write(1, &c, 1);
		i++;
	}
	j = 0;
	while (s2[j])
	{
		c = s2[j];
		if (!is_present(s1, c, i) && !is_present(s2, c, j))
			write(1, &c, 1);
		j++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
