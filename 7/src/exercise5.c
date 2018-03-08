/**
 * Exercise 5 - Create, Modify, Print, Free
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * Dynamically creates and initialises an array of size rows * cols (matrix), returns a pointer to the matrix
 * or NULL in case of error allocation.
 *
 * @param rows number of rows
 * @param cols number of columns
 * @return dynamically created array (matrix) or NULL in case of allocation error
 */
int **create_matrix(int rows, int cols)
{
	// allocates memory for pointers to cols
	int **matrix;
	if (!(matrix = (int **) malloc(rows * sizeof(int *))))
	{
		return NULL;
	}

	// allocates memory for particular cloumn values
	for (int i = 0; i < rows; i++)
	{
		if (!(matrix[i] = (int *) malloc(cols * sizeof(int))))
		{
			// in case of error deallocates all already allocated memory
			for (int j = 0; j < i; j++)
			{
				free(matrix[j]);
			}
			free(matrix);

			return NULL;
		}

		// initialises matrix values
		for (int j = 0; j < rows; j++)
		{
			matrix[i][j] = 0;
		}
	}

	return matrix;
}


/**
 * Frees an matrix of given rows.
 *
 * @param matrix matrix to be freed
 * @param rows number of rows
 */
void free_matrix(int **matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}


/**
 * Takes array (matrix) and dimensions, prints out the contents formatted by row and column.
 *
 * @param matrix array (matrix) to be printed
 * @param rows number of rows
 * @param cols number of columns
 */
void print_matrix(int **matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		putchar('\n');
	}
}


/**
 * Takes array (matrix) and dimensions, randomly sets each element to 1-9.
 *
 * @param matrix array (matrix) to be randomised
 * @param rows number of rows
 * @param cols number of columns
 */
void randomise_matrix(int **matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = 1 + (int) random() % 9;
		}
	}
}


int main()
{
	srandom((unsigned int) time(NULL));

	// gets dimensions from user
	int rows, cols;
	printf("Enter rows: ");
	scanf("%d", &rows);
	printf("Enter cols: ");
	scanf("%d", &cols);

	// creates matrix
	int **matrix;
	if (!(matrix = create_matrix(rows, cols)))
	{
		printf("Allocation error.\n");
		return EXIT_FAILURE;
	}

	// prints matrix
	printf("\nEmpty matrix:\n");
	print_matrix(matrix, rows, cols);

	// modifies matrix
	randomise_matrix(matrix, rows, cols);

	// prints matrix
	printf("\nRandomised matrix:\n");
	print_matrix(matrix, rows, cols);

	// frees matrix
	free_matrix(matrix, rows);

	return EXIT_SUCCESS;
}
