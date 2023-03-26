/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:47:28 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/23 15:25:58 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

 void	handle_sigtstp(int sig)
 {
	printf("Suspended not allowed\n");
	
 }
 
  void	handle_sigcont(int sig)
 {
	printf("Input number: ");
	fflush(stdout); // so it actually prints number not waiting for back session 
 }

int	main(int argc, char* argv[])
{
	struct sigaction	sa;
	// sa.sa_handler = &handle_sigtstp;
	sa.sa_handler = &handle_sigcont; 
	sa.sa_flags = SA_RESTART; /* does no have to be used for all signal handlers but does have to be used with this one */
	// sigaction(SIGTSTP, &sa, NULL); 
	sigaction(SIGCONT, &sa, NULL); 
	
	/* here we hook action into proper signal */
	/* sigaction is recommended over signal because if you want to restore the functionality of 
	previous handlers it's easier with sigaction becuase of the third peramiter */
	
	int x;
	printf("Input number: ");
	scanf("%d", &x); //you do not have to set up flag if you are not using scanf
	printf("Result %d * 5 = %d\n", x, x * 5);
	return 0;
}
