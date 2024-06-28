/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:17:01 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/28 14:42:59 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

int underscore_occ(char *str)
{
	int i = 0;
	int n = 0;

	while (str[i])
	{
		if (str[i] == '_')
			n++;
		i++;
	}
	return (n);
}

char	*snake_to_camel(char *str)
{
	if (!str)
		return (NULL);
	int	i = 0;
	int j = ft_strlen(str) - underscore_occ(str);
	char *dest = malloc((sizeof(char) * j) + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (str[i])
	{
		if (str[i] == '_')
		{
			i++;
			if (str[i] >= 'a' && str[i] <= 'z')
				dest[j++] = str[i] - 32;
		}
		else
			dest[j++] = str[i];
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int	main(int argc, char *argv[])
{
	char *dest;

	if (argc == 2)
	{
		dest = snake_to_camel(argv[1]);
		if (dest)
		{
			write(1, dest, ft_strlen(dest));
			free(dest);
		}
	}
	write(1, "\n", 1);
	return (0);
}
