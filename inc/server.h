/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:37:15 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/26 19:43:33 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "./libft/libft.h"
# include <signal.h>
# include <unistd.h>

// void	ft_putchar_fd(char c, int fd);
// void	ft_putnbr_fd(int n, int fd);
void	receive(int sig);
int	main(void);


#endif