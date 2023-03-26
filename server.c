/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:28:24 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/26 19:45:05 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	receive(int sig)
{
	static int				i = 0;
	static unsigned char	k = '\0';  //why are these static?

	if(sig == SIGUSR1)
		i++;
	if (sig == SIGUSR2)
	{
		if (i != 7)
			k += 1 << i; // bit shifting to reassemble binary
		i++;
	}
	if (i == 7)
	{
		write(1, &k, 1);
		i = 0;
		k = '\0';
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1); //why is it 1
	write(1, "\n", 1);
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while(1)
		pause(); // is pause the same as wait?
	return (0);
}
