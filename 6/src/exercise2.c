/**
 * Exercise 2 – Array pointers
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
	int myArray[] = {10, 20, 30, 40, 50, 60, 70, 80};

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", myArray[i]);
	}

	putchar('\n');

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", *(myArray + i));
	}

	return EXIT_SUCCESS;
}
