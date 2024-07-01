/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:16:10 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/01 14:57:29 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static size_t ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static void	ft_print_word(char *str)
{
	while (*str && !ft_isspace(*str))
		write(1, str++, 1);
}

void	rev_wstr(char *str)
{
	size_t	len = ft_strlen(str);
	size_t	end = len;
	size_t	start;

	while (end > 0)
	{
		while (end > 0 && ft_isspace(str[end - 1]))
			end--;
		if (end == 0)
			break;
		start = end;
		while (start > 0 && !ft_isspace(str[start - 1]))
			start--;
		ft_print_word(&str[start]);
		if (start > 0)
			write(1, " ", 1);
		end = start;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
