/**
 * Exercise 6 - Ternary Operator
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("Enter two number (separated by space): ");
	int number1, number2;
	scanf("%d %d", &number1, &number2);

	printf("%s", number1 == number2 ? "These numbers are equal.\n" : "These numbers are not equal.\n");
	printf("%s", number1 > number2 ? "First number is greater than second number.\n" : "");
	printf("%s", number1 & 1 && number2 & 1 ? "Both numbers are odd.\n" : "");
	printf("%s", !(number1 & 1) && !(number2 & 1) ? "Both numbers are even.\n" : "");

	return EXIT_SUCCESS;
}
