/**
 * Exercise 1 – Mass Converter
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void print_options()
{
	printf(
		"1. Ounces to grams\n"
		"2. Grams to ounces\n"
		"3. Pounds to stones\n"
		"4. Stones to pounds\n"
		"5. Exit\n"
	);
}


float ounces_to_grams(float ounces)
{
	static const float grams_in_ounce = 28.3495;

	return ounces * grams_in_ounce;
}


float grams_to_ounces(float grams)
{
	static const float ounces_in_grams = 0.035274;

	return grams * ounces_in_grams;
}


float pounds_to_stones(float pounds)
{
	static const float stones_in_pounds = 0.0714286;

	return pounds * stones_in_pounds;
}


float stones_to_pounds(float stones)
{
	static const float pounds_in_stones = 14.0;

	return stones * pounds_in_stones;
}


int main()
{
	printf(
		"--------------\n"
		"Mass Converter\n"
		"--------------\n"
	);

	bool exit = false;
	do
	{
		print_options();
		printf("\n\nChoice: ");
		int choice;
		scanf("%d", &choice);

		float input;
		switch (choice)
		{
			case 1:
				printf("\nEnter ounces: ");
				scanf("%f", &input);
				printf("%g ounces is %g grams.\n\n\n", input, ounces_to_grams(input));
				break;

			case 2:
				printf("\nEnter grams: ");
				scanf("%f", &input);
				printf("%g grams is %g ounces.\n\n\n", input, grams_to_ounces(input));
				break;

			case 3:
				printf("\nEnter pounds: ");
				scanf("%f", &input);
				printf("%g pounds is %g stones.\n\n\n", input, pounds_to_stones(input));
				break;

			case 4:
				printf("\nEnter stones: ");
				scanf("%f", &input);
				printf("%g stones is %g pounds.\n\n\n", input, stones_to_pounds(input));
				break;

			case 5:
				exit = true;
				break;

			default:
				printf("Unknown choice.");
				return EXIT_FAILURE;
		}
	}
	while (!exit);

	return EXIT_SUCCESS;
}
