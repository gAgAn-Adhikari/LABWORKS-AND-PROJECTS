
/*
* main.c
*
* Created: 10/06/2025 4:06:45 PM
* Author: eric chen
*/
#include <stdio.h>
#include <inttypes.h>
//global variables
int g ;
float f;
int main(void)
{
	while(1)
	{
		//local variables
		int size_int = sizeof (int);
		int size_int16 = sizeof (int16_t);
		int *p = &g;
		int16_t x = 0x1234, y = 4, z;
		int16_t *p_x = &x;
		int16_t *p_y = &y;
		char ch1 ='0', ch2;
		char *p_ch1 = &ch1;
		ch2 = ch1 + 2;
		z = x + y;
		//y = (x>>1) + g++; //using shift right by 1 positions for division by
		2
		y = x / 2 + g++; //division operator
		f = 3.14 * z;
	}
	return 0;
}
