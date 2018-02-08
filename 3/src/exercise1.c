/**
 * Exercise 1: Temperature Conversion
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


float celsius_to_fahrenheit(float celsius)
{
	return celsius * (9.0f / 5.0f) + 32.0f;
}


float fahrenheit_to_celsius(float fahrenheit)
{
	return (fahrenheit - 32.0f) * (5.0f / 9.0f);
}


int main()
{
	printf("***** Temperature Conversion *****\n");

	printf("Would you like to convert from Celsius to Fahrenheit (enter C) or from Fahrenheit to Celsius (enter F)? ");
	char conversion;
	scanf("%c", &conversion);
	conversion = (char) tolower(conversion);

	float temperature;
	if (conversion == 'c')
	{
		printf("Enter temperature in Celsius: ");
		scanf("%f", &temperature);
		printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
	}
	else if (conversion == 'f')
	{
		printf("Enter temperature in Fahrenheit: ");
		scanf("%f", &temperature);
		printf("%.2f Fahrenheit is %.2f Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
	}
	else
	{
		printf("Unknown conversion option entered.\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
