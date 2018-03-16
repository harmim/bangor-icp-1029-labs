/**
 * Exercise 3 - Modified Bubble Sort
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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
	bool swapped = true;
	for (int i = 0; swapped; i++)
	{
		swapped = false;
		for (int j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				swapped = true;
			}
		}
	}
}


int main()
{
	int array[10] = {5, 1, 3, 2, 4, 0, 7, 6, 8, 9};

	printf("Original array: ");
	print_array(array, SIZE);

	bubble_sort(array, SIZE);
	printf("Sorted array: ");
	print_array(array, SIZE);

	return EXIT_SUCCESS;
}
