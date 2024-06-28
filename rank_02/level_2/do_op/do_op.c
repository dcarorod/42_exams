/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:55:59 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/28 08:12:53 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	do_op(int num1, int num2, char *operation)
{
	int	result;

	result = 0;
	if (operation[0] == '+')
		result = num1 + num2;
	else if (operation[0] == '-')
		result = num1 - num2;
	else if (operation[0] == '*')
		result = num1 * num2;
	else if (operation[0] == '/')
		result = num1 / num2;
	else if (operation[0] == '%')
		result = num1 % num2;
	return (result);
}


int	main(int argc, char *argv[])
{
	int		num1;
	int		num2;
	char	*op;
	int		result;

	if (argc == 4)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);
		op = argv[2];
		result = do_op(num1, num2, op);
		printf("%d", result);
	}
	printf("\n");
	return (0);
}
