/**
 * Exercise 5 – Vowel Exterminator
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("String is: ");
	char string[256];
	fgets(string, 256, stdin);

	int count_a = 0, count_e = 0, count_i = 0, count_o = 0, count_u = 0;
	char string_without_vowels[256] = {0};
	for (int i = 0, j = 0; string[i] != '\0'; i++)
	{
		switch (string[i])
		{
			case 'a':
				count_a++;
				break;

			case 'e':
				count_e++;
				break;

			case 'i':
				count_i++;
				break;

			case 'o':
				count_o++;
				break;

			case 'u':
				count_u++;
				break;

			default:
				string_without_vowels[j++] = string[i];
				break;
		}
	}
	printf("Vowel Count a:%d, e:%d, i:%d, o:%d, u:%d\n", count_a, count_e, count_i, count_o, count_u);
	printf("String without vowels: %s\n", string_without_vowels);

	return EXIT_SUCCESS;
}
