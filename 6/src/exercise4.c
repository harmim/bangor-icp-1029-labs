/**
 * Exercise 4 – Pointer Reverse
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reverse_and_print(const char *str)
{
	for (int i = (int) strlen(str) - 1; i >= 0; i--)
	{
		putchar(str[i]);
	}
	putchar('\n');
}


void reverse(const char *src, char *dst)
{
	int dst_position = 0;
	for (int i = (int) strlen(src) - 1; i >= 0; i--)
	{
		dst[dst_position++] = src[i];
	}
	dst[dst_position] = '\0';
}


int main()
{
	reverse_and_print("Dominik");

	char str[] = "Dominik";
	char reversed_str[strlen(str)];
	reverse(str, reversed_str);
	printf("%s\n", reversed_str);

	return EXIT_SUCCESS;
}
