/**
 * Exercise 2 - Sequences
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
	// 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
	for (int i = 10; i <= 100; i += 10)
	{
		printf("%d%s", i, i != 100 ? ", " : "\n");
	}

	// -10, -8, -6, -4, -2, 0, 2, 4, 6, 8, 10
	for (int i = -10; i <= 10; i += 2)
	{
		printf("%d%s", i, i != 10 ? ", " : "\n");
	}

	// 1, 2, 3, 4, 5, 4, 3, 2, 1
	for (int i = 1, down = 0; i > 0;)
	{
		printf("%d%s", i, i != 1 || !down ? ", " : "\n");
		down ? i-- : i++;
		if (i == 5)
		{
			down = 1;
		}
	}

	// The ASCII English alphabet (uppercase)
	for (int i = 65; i <= 90; i++)
	{
		printf("%c%s", i, i != 90 ? ", " : "\n");
	}

	// The ASCII English alphabet (lowercase)
	for (int i = 97; i <= 122; i++)
	{
		printf("%c%s", i, i != 122 ? ", " : "\n");
	}

	// English alphabet without vowels (a e i o u)
	for (int i = 97; i <= 122; i++)
	{
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
		{
			continue;
		}

		printf("%c%s", i, i != 122 ? ", " : "\n");
	}

	return EXIT_SUCCESS;
}
