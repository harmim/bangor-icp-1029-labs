/**
 * Exercise 4 – Selection sort
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


#define SIZE 10


void print_array(const int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	putchar('\n');
}


void selection_sort(int *array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		int tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
	}
}


int main()
{
	int array[10] = {5, 1, 3, 2, 4, 0, 7, 6, 8, 9};

	printf("Original array: ");
	print_array(array, SIZE);

	selection_sort(array, SIZE);
	printf("Sorted array: ");
	print_array(array, SIZE);

	return EXIT_SUCCESS;
}
