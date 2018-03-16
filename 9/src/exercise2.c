/**
 * Exercise 2 - Alphabetical
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


#define SIZE 27


void bubble_sort(char *array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				char tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
}


int main()
{
	char array[SIZE] = "bazdcofqespnrxtwjyvhulmkgi";

	printf("Original array: %s\n", array);

	bubble_sort(array, SIZE - 1);
	printf("Sorted array: %s\n", array);

	return EXIT_SUCCESS;
}
