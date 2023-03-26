/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_NOT.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:22:49 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/26 16:23:29 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//there is a varient to the or which is  ~ ( NOT) 
// in bitwise all this does is flip the bit

int	main(int argc, char* argv[])
{
	int r;
	r = ~5; // in base 2 is actually 10 (one zero)
	printf("Result: %d\n", r);
	return	0;
}

// 128| 64| 32| 16|  8|  4|  2|  1
// -------------------------------
//   0|  0|  0|  0|  0|  1|  0|  1  --> 5 
//becomes
//   1|  1|  1|  1|  1|  0|  1|  0  --> 2
// -------------------------------
//                                
