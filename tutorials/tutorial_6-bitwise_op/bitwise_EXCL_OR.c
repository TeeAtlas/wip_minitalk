/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_EXCL_OR.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:20:36 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/26 16:22:24 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//there is a varient to the or which is  ^ ( EXCLUSIVE OR) in bitwise 

int	main(int argc, char* argv[])
{
	int r;
	r = 9 ^ 5; // in base 2 is actually 10 (one zero)
	printf("Result: %d\n", r);
	return	0;
}

// 128| 64| 32| 16|  8|  4|  2|  1
// -------------------------------
//   0|  0|  0|  0|  1|  0|  0|  1  --> 9
//   0|  0|  0|  0|  0|  1|  0|  1  --> 5
// -------------------------------
//               0|  1|  1|  0|  0  --> 12