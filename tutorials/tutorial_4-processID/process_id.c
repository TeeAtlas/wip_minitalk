/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:34:33 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/25 17:13:12 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(int argc, char* argv[])
{
	int id = fork();
	if (id == 0)
		sleep(1);
	printf("Current ID: %d, Parent ID: %d\n", \
		getpid(), getppid());
	
	int res = wait(NULL);
	// if (id != 0) // if we are in the parent process
	if (res == -1) //without wait a new parent will be assigned so that processes will have an id and wont finish program
		printf ("No chilren to wait for.\n");
	else
		printf("%d Finished execution.\n", res);
	return 0;
}
