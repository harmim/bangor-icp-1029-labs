/**
 * Chatbot
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 * @version 0.1
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define FT_IN_CM 0.0328084
#define PD_IN_KG 2.20462


int main()
{
	/// Welcome message
	char welcome_message[] =
		"------------\n"
		"Chatbot v0.1\n"
		"------------\n"
		"I am a chatbot\n"
		"You are a human\n"
		"I have five quiestions for you!\n";
	printf("%s\n", welcome_message);


	/// Asking questions

	// first question - first name
	char first_name[80];
	printf("What is your first name? ");
	scanf("%79s", first_name);

	// second question - surname
	char surname[80];
	printf("What is your surname? ");
	scanf("%79s", surname);

	// third question - year of born
	int born_year;
	printf("What year were you born? ");
	scanf("%d", &born_year);

	// fourth question - height
	float height_cm;
	printf("How tall are you in centimeters? ");
	scanf("%f", &height_cm);

	// fiveth question - weight
	float weight_kg;
	printf("What is your weight in kilograms? ");
	scanf("%f", &weight_kg);


	/// Priting and calculating deductions and conversions

	printf("\n");

	// name
	printf("Your name is %s %s.\n", first_name, surname);

	// age
	time_t current_time;
	time(&current_time);
	struct tm current_time_struct = *gmtime(&current_time);
	printf("You are about %d years old.\n", current_time_struct.tm_year + 1900 - born_year);

	// height and weigh
	printf("You are about %.2f feet tall and weigh %.2f pounds.\n", height_cm * FT_IN_CM, weight_kg * PD_IN_KG);


	return EXIT_SUCCESS;
}
