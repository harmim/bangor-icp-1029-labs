/**
 * Exercise 3 - Row after row after row
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


#define ROWS 2
#define COLS 3


int main()
{
	int array[ROWS][COLS] = {
		{1, 2, 3},
		{4, 5, 6},
	};

	printf("Prints by rows:\n");
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			printf("array[%d, %d] = %d\n", r, c, array[r][c]);
		}
	}

	printf("\nPrints by cols:\n");
	for (int c = 0; c < COLS; c++)
	{
		for (int r = 0; r < ROWS; r++)
		{
			printf("array[%d, %d] = %d\n", r, c, array[r][c]);
		}
	}

	return EXIT_SUCCESS;
}
