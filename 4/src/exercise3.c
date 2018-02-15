/**
 * Exercise 3 – Asterisk Party
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


int main()
{
	srand((unsigned int) time(NULL));

	char c;
	while (tolower(c = (char) getchar()) != 'q')
	{
		if (c == '\n')
		{
			int rand_val = 1 + (rand() % 20);
			for (int i = 0; i < rand_val; i++)
			{
				putchar('*');
			}
		}
	}

	return EXIT_SUCCESS;
}
