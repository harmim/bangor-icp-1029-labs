/**
 * Exercise 2 – Min Max
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("Please enter three numbers (separated by space): ");
	int number1, number2, number3;
	scanf("%d %d %d", &number1, &number2, &number3);

	int min = number2, max = number1;
	if (number2 > number1)
	{
		max = number2;
		min = number1;
	}
	if (number3 > max)
	{
		max = number3;
	}
	if (number3 < min)
	{
		min = number3;
	}

	printf("Smallest number is %d.\n", min);
	printf("Largest number is %d.\n", max);

	return EXIT_SUCCESS;
}
