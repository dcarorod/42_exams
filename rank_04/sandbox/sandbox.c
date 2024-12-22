/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:02:46 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/22 23:05:18 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h> // exit
#include <unistd.h> // fork, alarm
#include <sys/wait.h> // waitpid
#include <signal.h> // sigaction, kill, strsignal
#include <errno.h> // errno
#include <stdio.h>
#include <string.h>

#define NICE_FUNCTION 1
#define BAD_FUNCTION 0
#define ERROR_FUNCTION -1

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	pid_t	pid;
	pid_t	wait_pid;
	int		wstatus;

	pid = fork();
	if (pid == -1) // error
		return (-1);
	else if (pid == 0) //in child
	{
		f();
		exit(0);
	}
	else //in parent
	{
		if (timeout > 0)
			alarm(timeout);
		wait_pid = waitpid(pid, &wstatus, 0);
		alarm(0);
		if (wait_pid == -1)
		{
			if (errno == EINTR)
			{
				kill(pid, SIGKILL);
				if (verbose)
					printf("Bad function: timed out after %d seconds\n", timeout);
				waitpid(pid, NULL, 0); // clean up zombie process
				return (BAD_FUNCTION);
			}
			return (ERROR_FUNCTION);
		}
		if (WIFSIGNALED(wstatus))
		{
			if (verbose)
				printf("Bad function: %s\n", strsignal(WTERMSIG(wstatus)));
			return (BAD_FUNCTION);
		}
		if (WIFEXITED(wstatus))
		{
			int	exit_code = WEXITSTATUS(wstatus);
			if (exit_code != 0)
			{
				if (verbose)
					printf("Bad function: exited with code: %d\n", exit_code);
				return (BAD_FUNCTION);
			}
		}
		if (verbose)
			printf("Nice function!\n");
		return (NICE_FUNCTION);
	}
}
