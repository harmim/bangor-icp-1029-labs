/**
 * Exercise 5 – Insertion sort
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


void insertion_sort(int *array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int item = array[i], j;
		for (j = i - 1; j >= 0 && array[j] > item; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = item;
	}
}


int main()
{
	int array[10] = {5, 1, 3, 2, 4, 0, 7, 6, 8, 9};

	printf("Original array: ");
	print_array(array, SIZE);

	insertion_sort(array, SIZE);
	printf("Sorted array: ");
	print_array(array, SIZE);

	return EXIT_SUCCESS;
}
