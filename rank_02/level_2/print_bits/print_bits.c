/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:53:49 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/28 12:06:33 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		if (octet & (1 << i))
			bit = '1';
		else
			bit = '0';
		write(1, &bit, 1);
		i--;
	}
}

/*int main()
{
	unsigned char value = 2;
	print_bits(value);  // Expected output: 00000010
	return 0;
}*/
