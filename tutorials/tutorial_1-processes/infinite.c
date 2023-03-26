/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:38:56 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/22 16:37:59 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main()
{
	while(1)
		printf("%d Infinite Loop\n", getpid()); /* pid is process id */
}