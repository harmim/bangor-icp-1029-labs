/**
 * Exercise 2 - Columns and Rows
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


#define ROWS 5
#define COLS 4


int main()
{
	int array[ROWS][COLS] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
		{17, 18, 19, 20},
	};

	printf("Backwards print:\n");
	for (int i = ROWS - 1; i >= 0; i--)
	{
		for (int j = COLS - 1; j >= 0; j--)
		{
			printf("array[%d][%d] = %d\n", i, j, array[i][j]);
		}
	}

	printf("\nBy row and column print:\n");
	for (int i = ROWS - 1; i >= 0; i--)
	{
		for (int j = COLS - 1; j >= 0; j--)
		{
			printf("%-5d", array[i][j]);
		}
		putchar('\n');
	}

	return EXIT_SUCCESS;
}
