/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_kill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:04:49 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/25 15:34:24 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	x = 0;

void	handle_sigusr1(int sig)
{
	if (x == 0)
		printf("\nHint: 5 and 5 and 5!\n");
	
}

int	main(int argc, char* argv[])
{
	int	pid = fork();
	if (pid == - 1) // if process id is negative 1 it's going to produce an error code
		return 1;
	if (pid == 0)
	{
		//child process
		// we are saying if the parent waits 5 seconds we send the kill function
		sleep(5);
		// kill function takes in the process id (pid)
		// can get parent process id by saying getppid
		kill(getppid(), SIGUSR1);
		
		
	}
	else
	{
		struct sigaction sa = { 0 }; //sets all members to zero
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);
		
		// parent process
		printf("What is the result of 3 x 5: ");
		scanf("%d", &x);
		if (x == 15)
			printf("You are correct!\n");
		else 
			printf("You are totally wrong!\n");
		wait(NULL);
	}

	return 0;
}