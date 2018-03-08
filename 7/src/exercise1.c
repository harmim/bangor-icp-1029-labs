/**
 * Exercise 1 - Passing by Reference
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


void square(int *num)
{
	*num = *num * *num;
}


int main()
{
	int x = 4;
	square(&x);
	printf("%d\n", x);

	return EXIT_SUCCESS;
}
