/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:20:35 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/02 15:18:55 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

static	void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static int	has_no_sp(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

static void	ft_print_word(char *str)
{
	while (*str && !ft_isspace(*str))
		write(1, str++, 1);
}

static size_t	word_len(char *str)
{
	size_t	len = 0;
	while(str[len] && !ft_isspace(str[len]))
		len++;
	return (len);
}

static char	*copy_word(char *src, size_t len)
{
	size_t	i = 0;

	if (!src || len <= 0)
		return (NULL);
	char *dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[i] && !ft_isspace(src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	rostring(char *str)
{
	char	*first_word;
	size_t	fw_len;

	if (!str || !*str)
		return ;
	if (has_no_sp(str))
	{
		ft_putstr(str);
		return ;
	}
	while (*str && ft_isspace(*str))
		str++;
	fw_len = word_len(str);
	first_word = copy_word(str, fw_len);
	if (!first_word)
		return ;
	str += fw_len;
	while (ft_isspace(*str))
		str++;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		ft_print_word(str);
		while (*str && !ft_isspace(*str))
			str++;
		while (ft_isspace(*str))
			str++;
		if (*str)
			write(1, " ", 1);
	}
	write(1, " ", 1);
	ft_putstr(first_word);
	free(first_word);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
