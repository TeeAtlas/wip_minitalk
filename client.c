/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:28:20 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/27 18:42:36 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] >= 48 || str[i] == 45)
		i++;
	while (str[i] >= 48 && str[i] <= 57) // could be handled with is digit function 
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (sign * res);
}

void	send_message(int pid, char *str)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (j < 7)
	{
		if ((str[i] & 1) == 0) // sending string as ascii to binary per character
			kill(pid, SIGUSR1);
		if ((str[i] & 1) == 1)
			kill(pid, SIGUSR2);
		str[i] = str[i] >> 1; // we are shifting bits to the right until statement is true
		j++;
		usleep(200); //using sleep to avoid a delay, wherein the information can get jumbled
	}
	i++;
}

int	main(int argc, char **argv)
{
	int	pid;
	
	if (argc != 3)
	{
		write(1, "Invalid Args!\n ./client [PID] [STR]\n", 40);
		exit(0);
	}
	pid = ft_atoi(argv[1]); //first argument which is the pid
	send_message(pid, argv[2]); //second arguement is the string
	return (0);
}