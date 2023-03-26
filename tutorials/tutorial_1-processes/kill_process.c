/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:44:42 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/22 16:39:22 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <signal.h>

int	main()
{
	int pid = 0;
	
	printf("Introduce the PID: ");
	scanf("%d", &pid);

	kill(pid, SIGTERM);
}