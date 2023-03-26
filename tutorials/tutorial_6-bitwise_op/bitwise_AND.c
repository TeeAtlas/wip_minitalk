/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_AND.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:18:03 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/26 16:23:28 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char* argv[])
{
	int r;
	r = 1 & 1;
	printf("Result: %d\n", r);
	return	0;
}



// Bitwise AND (&) operator 
 
// bit a	bit b	a & b (a AND b)
// 0		0		0
// 0		1		0
// 1		0		0
// 1		1		1

// why? 

//so, if we have:

// int	main(int argc, char* argv[])
// {
// 	int r;
// 	r = 1 & 2; // in base 2 is actually 10 (one zero)
// 	printf("Result: %d\n", r);
// 	return	0;
// }

// the result will be 0
// because as it's represented
//  1
// 10		butwise only looks at columns and gives results as such
// 00



// int	main(int argc, char* argv[])
// {
// 	int r;
// 	r = 9 & 5; // in base 2 is actually 10 (one zero)
// 	printf("Result: %d\n", r);
// 	return	0;
// }


// 128| 64| 32| 16|  8|  4|  2|  1
// -------------------------------
//   0|  0|  0|  0|  1|  0|  0|  1  --> 9
//   0|  0|  0|  0|  0|  1|  0|  1  --> 5
// --------------------------------
//                   0|  0|  0|  1  --> 1
