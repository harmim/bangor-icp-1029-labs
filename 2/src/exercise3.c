/**
 * Exercise 3: Input
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
	int value1;
	printf("Please enter first whole number: ");
	scanf("%d", &value1);

	int value2;
	printf("Please enter second whole number: ");
	scanf("%d", &value2);

	printf("First number + second number equals: %d\n", value1 + value2);

	return EXIT_SUCCESS;
}
