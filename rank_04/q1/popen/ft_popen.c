/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:42:57 by dcaro-ro          #+#    #+#             */
/*   Updated: 2025/02/10 18:10:08 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	int	fd[2];
	pid_t	pid;

	if (!file || !argv)
		return (-1);
	if (type != 'r' && type != 'w')
	{
		printf("wrong type\n");
		return (-1);
	}
	if (pipe(fd) == -1)
	{
		printf("pipe failed\n");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
		}
		if (type == 'w')
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close (fd[0]);
		}
		execvp(file, argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (type == 'r')
		{
			close(fd[1]);
			return (fd[0]);
		}
		if (type == 'w')
		{
			close(fd[0]);
			return (fd[1]);
		}
	}
	return (-1);
}

