/**
 * Exercise 6: Macro Calculator
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define ADDITION(_value1, _value2) ((_value1) + (_value2))
#define SUBTRACTION(_value1, _value2) ((_value1) - (_value2))
#define MULTIPLICATION(_value1, _value2) ((_value1) * (_value2))
#define DIVISION(_value1, _value2) ( (float) (_value1) / (_value2))
#define AVERAGE(_value1, _value2) (((_value1) + (_value2)) / 2.0)
#define POWER(_value1, _value2) pow(_value1, _value2)


int main()
{
	int value1;
	printf("Please enter first whole number: ");
	scanf("%d", &value1);

	int value2;
	printf("Please enter second number: ");
	scanf("%d", &value2);

	printf("\n");
	printf("%d + %d = %d\n", value1, value2, ADDITION(value1, value2));
	printf("%d - %d = %d\n", value1, value2, SUBTRACTION(value1, value2));
	printf("%d * %d = %d\n", value1, value2, MULTIPLICATION(value1, value2));
	printf("%d / %d = %.2f\n", value1, value2, DIVISION(value1, value2));
	printf("Average: %.2f\n", AVERAGE(value1, value2));
	printf("%d pow %d = %.2f\n", value1, value2, POWER(value1, value2));

	return EXIT_SUCCESS;
}
