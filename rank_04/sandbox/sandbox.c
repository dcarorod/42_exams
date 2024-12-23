/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:02:46 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/23 18:35:20 by dcaro-ro         ###   ########.fr       */
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
	int		wstatus; // status of child process

	pid = fork();
	if (pid == -1) // error
		return (-1);
	else if (pid == 0) // child process
	{
		f();
		exit(0);
	}
	else // parent process
	{
		if (timeout > 0)
			alarm(timeout);
		wait_pid = waitpid(pid, &wstatus, 0); // wait for child process to finish
		alarm(0); // cancel alarm
		if (wait_pid == -1)
		{
			//If the child process doesn't finish execution within this time frame,
			//the SIGALRM signal is sent to the parent process.
			if (errno == EINTR) // wait was interrupted by signal (SIGALRM)
			{
				kill(pid, SIGKILL); // kill the child process
				if (verbose)
					printf("Bad function: timed out after %d seconds\n", timeout);
				waitpid(pid, NULL, 0); // clean up zombie process
				return (BAD_FUNCTION);
			}
			return (ERROR_FUNCTION);
		}
		if (WIFSIGNALED(wstatus)) // child process terminated by a signal
		{
			if (verbose)
				printf("Bad function: %s\n", strsignal(WTERMSIG(wstatus)));
			return (BAD_FUNCTION);
		}
		if (WIFEXITED(wstatus)) // child process terminated normally
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

// void nice_function(void)
// {
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("Counting: %d\n", i);
// 		sleep(1);
// 	}
// }

// void bad_function(void)
// {
// 	printf("This function is about to crash.\n");
// 	int *ptr = NULL;
// 	*ptr = 42; // Dereferencing a null pointer
// }

// void very_bad_function1(void)
// {
// 	printf("Infinite loop started...\n");
// 	while (1) {} // Never stops
// }

// #include <time.h>

// void very_bad_function(void)
// {
// 	srand(time(NULL));
// 	int behavior = rand() % 3;

// 	if (behavior == 0)
// 	{
// 		printf("I will crash now.\n");
// 		int *ptr = NULL;
// 		*ptr = 42; // Cause a crash
// 	}
// 	else if (behavior == 1)
// 	{
// 		printf("I will loop forever.\n");
// 		while (1) {} // Infinite loop
// 	}
// 	else
// 	{
// 		printf("I will exit with a bad code.\n");
// 		exit(1); // Non-zero exit status
// 	}
// }

// int main(void)
// {
// 	printf("Testing nice function 1:\n");
// 	sandbox(nice_function, 5, true);

// 	printf("\nTesting bad function:\n");
// 	sandbox(bad_function, 3, true);

// 	printf("\nTesting very bad function:\n");
// 	sandbox(very_bad_function, 3, true);

// 	return (0);
// }
