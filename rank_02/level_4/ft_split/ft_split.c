/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:25:13 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/30 17:49:33 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static size_t	count_words(char const *str)
{
	int		in_word;
	size_t	wc;
	int		i;

	in_word = 0;
	wc = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			if (in_word == 1)
				in_word = 0;
		}
		else if (in_word == 0)
		{
			wc++;
			in_word = 1;
		}
		i++;
	}
	return (wc);
}

static	size_t	ft_wordlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && !ft_isspace(str[len]))
		len++;
	return (len);
}

static char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	size_t	i = 0;
	size_t	wlen = 0;
	char	**dest;
	size_t		wc = count_words(str);

	dest = malloc(sizeof(char *) * (wc + 1));
	if (!dest)
		return (NULL);
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			wlen = ft_wordlen(str);
			dest[i] = malloc(sizeof(char) * (wlen + 1));
			if (!dest[i])
			{
				while (i > 0)
					free(dest[--i]);
				free(dest);
				return (NULL);
			}
			ft_strncpy(dest[i], str, wlen);
			i++;
		}
		str += wlen;
	}
	dest[i] = NULL;
	return (dest);
}

/*
#include <stdio.h>
int	main(void)
{
	char *input = "      Hello, 	world! \nThis is a test string.";
	char **words = ft_split(input);

	if (!words)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	for (int i = 0; words[i]; i++)
	{
		printf("Word %d: %s\n", i + 1, words[i]);
		free(words[i]);
	}
	free(words);
	return 0;
}
*/
