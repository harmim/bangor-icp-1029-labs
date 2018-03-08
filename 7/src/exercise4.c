/**
 * Exercise 4 - Random Crosses
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROWS 25
#define COLS 50


void generate_random_crosses(char array[ROWS][COLS], int count, int size)
{
	for (int i = 0; i < count; i++)
	{
		int row = size + (int) random() % (ROWS - 2 * size);
		int col = size + (int) random() % (COLS - 2 * size);
		array[row][col] = 'x';

		for (int j = 1; j <= size; j++)
		{
			array[row - j][col] = 'x'; // up
			array[row + j][col] = 'x'; // down
			array[row][col - j] = 'x'; // left
			array[row][col + j] = 'x'; // right
		}
	}
}


void print_array(char array[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%c ", array[i][j]);
		}
		putchar('\n');
	}
}


int main()
{
	srandom((unsigned int) time(NULL));

	char array[ROWS][COLS];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			array[i][j] = '.';
		}
	}

	printf("Empty array:\n");
	print_array(array);

	printf("\nArray with random crosses:\n");
	generate_random_crosses(array, 5, 2);
	print_array(array);

	return EXIT_SUCCESS;
}
