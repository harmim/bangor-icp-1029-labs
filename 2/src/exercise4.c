/**
 * Exercise 4: Simple Calculator
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	int value1;
	printf("Please enter first whole number: ");
	scanf("%d", &value1);

	int value2;
	printf("Please enter second number: ");
	scanf("%d", &value2);

	printf("\n");
	printf("%d + %d = %d\n", value1, value2, value1 + value2);
	printf("%d - %d = %d\n", value1, value2, value1 - value2);
	printf("%d * %d = %d\n", value1, value2, value1 * value2);
	printf("%d / %d = %.2f\n", value1, value2, (float) value1 / value2);
	printf("Average: %.2f\n", (value1 + value2) / 2.0);
	printf("%d pow %d = %.2f\n", value1, value2, pow(value1, value2));

	return EXIT_SUCCESS;
}
