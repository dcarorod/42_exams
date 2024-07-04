/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:51:52 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/04 17:04:11 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

static void	fill(char **tab, t_point size, char target, t_point cur)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y
		|| tab[cur.y][cur.x] != target || target == 'F')
		return ;

	tab[cur.y][cur.x] = 'F';

	t_point	up = {cur.x, cur.y - 1};
	t_point	down = {cur.x, cur.y + 1};
	t_point	left = {cur.x - 1, cur.y};
	t_point	right = {cur.x + 1, cur.y};

	fill(tab, size, target, up);
	fill(tab, size, target, down);
	fill(tab, size, target, left);
	fill(tab, size, target, right);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char	target = tab[begin.y][begin.x];

	fill(tab, size, target, begin);
}

/*
#include <stdlib.h>
#include <stdio.h>
char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
*/
