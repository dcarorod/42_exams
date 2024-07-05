/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:57:52 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/06 01:16:10 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len += ft_putchar(str[len]);
	return (len);
}

int	ft_strlen(const char *s)
{
	const char	*ptr;

	if (!s)
		return (0);
	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

int	ft_handle_str(va_list args)
{
	char	*str;
	char	*s;

	s = "(null)";
	str = va_arg(args, char *);
	if (!str)
		return (ft_putstr(s));
	return (ft_putstr(str));
}

int	ft_handle_int(int n)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		len += ft_handle_int(nbr / 10);
		nbr %= 10;
	}
	len += ft_putchar(nbr + '0');
	return (len);
}


static int	ft_num_length(unsigned int num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

static char	*ft_itoa_hex(unsigned int num)
{
	int			i;
	int			len;
	char		*hex_buffer;
	char		*hex_chars;

	hex_chars = "0123456789abcdef";
	len = ft_num_length(num, 16);
	hex_buffer = malloc(sizeof(char) * (len + 1));
	if (!hex_buffer)
		return (NULL);
	i = 0;
	while (i < len)
	{
		hex_buffer[i] = hex_chars[num % 16];
		num /= 16;
		i++;
	}
	hex_buffer[i] = '\0';
	return (hex_buffer);
}

int	ft_handle_hex(va_list args)
{
	int				i;
	int				len;
	char			temp;
	char			*hex_buffer;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	hex_buffer = ft_itoa_hex(num);
	if (!hex_buffer)
		return (0);
	len = ft_strlen(hex_buffer);
	i = 0;
	while (i < len / 2)
	{
		temp = hex_buffer[i];
		hex_buffer[i] = hex_buffer[len - i - 1];
		hex_buffer[len - i - 1] = temp;
		i++;
	}
	len = ft_putstr(hex_buffer);
	free(hex_buffer);
	return (len);
}

int	ft_handle_specifier(const char f, va_list args)
{
	if (f == 's' || f == 'd' || f == 'x')
	{
		if (f == 's')
			return (ft_handle_str(args));
		else if (f == 'd')
			return (ft_handle_int(va_arg(args, int)));
		else if (f == 'x')
			return (ft_handle_hex(args));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		char_count;
	va_list	args;

	va_start(args, format);
	i = 0;
	char_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			format++;
			char_count += ft_handle_specifier(format[i], args);
			while (format[i] && format[i] != 's' && format[i] != 'd' && format[i] != 'x')
				format++;
		}
		else
			char_count += ft_putchar(format[i]);
		format++;
	}
	va_end(args);
	return (char_count);
}
