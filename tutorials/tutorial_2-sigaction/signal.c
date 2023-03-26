/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:04:58 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/26 16:26:23 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

 void	handle_sigtstp(int sig)
 {
	printf("Suspended not allowed\n");
	
 }

int	main(int argc, char* argv[])
{
	signal(SIGTSTP, &handle_sigtstp); 
	/* not recommended to use signal because sigaction 
	is more portable and works on various versions of operation systems 
	but in your project you will use signal becuase it is a much easier function to use. 
	No fucking around :) */
		
	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return 0;
}
