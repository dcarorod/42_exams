/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:21:52 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/29 14:53:50 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		n;
	int		len;
	char	*str;

	i = 0;
	if (nbr == -2147483648)
		return ("-2147483648");
	len = ft_intlen(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
		str[0] = '-';
	n = ft_abs(nbr);
	i = len - 1;
	while (n)
	{
		str[i] = (n % 10) + '0';
		n = n /10;
		i--;
	}
	return (str);
}
