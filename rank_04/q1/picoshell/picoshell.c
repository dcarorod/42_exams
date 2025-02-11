/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picoshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:08:56 by dcaro-ro          #+#    #+#             */
/*   Updated: 2025/02/11 16:17:05 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int	picoshell(char **cmds[])
{
	pid_t	pid;
	int		fd[2];
	int		prev_fd;
	int		i;

	prev_fd = -1;
	i = 0;
	while (cmds[i])
	{
		if (cmds[i + 1])
		{
			if (pipe(fd) == -1)
				return (1);
		}
		pid = fork();
		if (pid == -1)
		{
			close(fd[0]);
			close(fd[1]);
			return (1);
		}
		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}
			if (cmds[i + 1])
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			close(fd[0]);
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		else
		{
			if (prev_fd != -1)
				close(prev_fd);
			close(fd[1]);
			prev_fd = fd[0];
		}
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
