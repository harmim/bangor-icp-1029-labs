/**
 * Exercise 1 - Bubble Sort
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


void bubble_sort(int *array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
}


int main()
{
	int array[SIZE] = {1, 3, 4, 5, 2, 3, 4, 5, 0, 8};

	printf("Original array: ");
	print_array(array, SIZE);

	bubble_sort(array, SIZE);
	printf("Sorted array: ");
	print_array(array, SIZE);

	return EXIT_SUCCESS;
}
