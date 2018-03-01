/**
 * Exercise 5 – Array of randoms
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void get_ten_random_numbers(int *result)
{
	for (int i = 0; i < 10; i++)
	{
		result[i] = ((int) random()) % 100 + 1;
	}
}


int main()
{
	srandom((unsigned int) time(NULL));
	int random_numbers[10];

	for (int i = 0; i < 10; i++)
	{
		get_ten_random_numbers(random_numbers);
		for (int j = 0; j < 10; j++)
		{
			printf("%-4d", random_numbers[j]);
		}
		putchar('\n');
	}

	return EXIT_SUCCESS;
}
