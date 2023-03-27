/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitshift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:06:44 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/27 13:05:50 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int	main(int argc, char *argv[])
// {
// 	unsigned int a = 1; // insigned 32 bit integer value is 1
	
// 	printf("Left shifted by 1: %d\n", a << 1);
// 	printf("Left shifted by 2: %d\n", a << 2);
// 	printf("Left shifted by 3: %d\n", a << 3);
// 	// result is 2, 4, 8 accordingly - every time doubles result
// 	return 0;
// }


// 128| 64| 32| 16|  8|  4|  2|  1
// -------------------------------
//   0|  0|  0|  0|  0|  0|  0|  1  --> 1
// when the bit is left shifted it becomes:
//   0|  0|  0|  0|  0|  0|  1|  0  --> 2
// -------------------------------
//                                

//using for loop to further illustrate bit shift assembly


// int	main(int argc, char *argv[])
// {
// 	int a = 5;
// 	// here's what's happening
// 	// 5 =  0101
// 	//10 =  1010
// 	//20 = 10100 in hexa decimal (14)
// 	// 4 =  0100 - line 30 no longer follows stucture becuase it was shifted so far out
// 	// it dissapeared off the boundry
// 	int i;
// 	for (i = 0; i < 32; i++){
// 		printf("Left shifted by %02d: %08x | %d\n", i, a << i, a << i);
// 	// we are shifting by i times starting at 0, 1, 2, 3 etc...
// 	}
	
// 	return 0;
// }



// // unsigned int
// int	main(int argc, char *argv[])
// {
// 	unsigned int a = 100000000;
// 	// here's what's happening
// 	// Right shifted by 00: 05f5e100 | 100000000	
// 	// Right shifted by 01: 02faf080 | 50000000
// 	// Right shifted by 02: 017d7840 | 25000000 
// 	// up until everything is populated with zeros
// 	int i;
// 	for (i = 0; i < 32; i++){
// 		printf("Right shifted by %02d: %08x | %u\n", i, a >> i, a >> i);
// 	// we are shifting by i times starting at 0, 1, 2, 3 etc...
// 	}
	
// 	return 0;
// }

// // signed int
// int	main(int argc, char *argv[])
// {
// 	int a = -100000000;
// 	// here's what's happening
// 	// Right shifted by 00: fa0a1f00 | -100000000
// 	// Right shifted by 01: fd050f80 | -50000000
// 	// Right shifted by 02: fe8287c0 | -25000000 
// 	// up until everything is populated with 1s(f being one in hexa)
// 	int i;
// 	for (i = 0; i < 32; i++){
// 		printf("Right shifted by %02d: %08x | %d\n", i, a >> i, a >> i);
// 	// we are shifting by i times starting at 0, 1, 2, 3 etc...
// 	}
	
// 	return 0;
// }

// note left shift and right shift have an assignment counterpart
// ex:
// a = a << 2;
// becomes:
// a <<= 2;

// signed int
int	main(int argc, char *argv[])
{
	int a = 100000000;
	
	a <<= 2;
	printf("%d\n", a);
	return 0;
}

// result 
// 400000000
// so int a x 4