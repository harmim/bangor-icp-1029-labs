/**
 * Exercise 8 - Time of day
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main()
{
	printf(
		"What time of day would you like?\n\n"
		"1. Night\n"
		"2. Early Morning\n"
		"3. Morning\n"
		"4. Afternoon\n"
		"5. Evening\n\n"
		"Choice: "
	);
	int choice;
	scanf("%d", &choice);
	printf("\n");

	srand((unsigned int) time(NULL));
	int minute = rand() % 60, hour;
	char part_of_day[20];
	switch (choice)
	{
		case 1:
			hour = rand() % 6;
			if (hour == 0)
			{
				minute = 1 + rand() % 59;
			}
			else if (hour == 5)
			{
				minute = 0;
			}
			strcpy(part_of_day, "Night");
			break;

		case 2:
			hour = 5 + rand() % 4;
			if (hour == 5)
			{
				minute = 1 + rand() % 59;
			}
			else if (hour == 8)
			{
				minute = 0;
			}
			strcpy(part_of_day, "Early Morning");
			break;

		case 3:
			hour = 8 + rand() % 5;
			if (hour == 8)
			{
				minute = 1 + rand() % 59;
			}
			else if (hour == 12)
			{
				minute = 0;
			}
			strcpy(part_of_day, "Morning");
			break;

		case 4:
			hour = 12 + rand() % 7;
			if (hour == 12)
			{
				minute = 1 + rand() % 59;
			}
			else if (hour == 18)
			{
				minute = 0;
			}
			strcpy(part_of_day, "Afternoon");
			break;

		case 5:
			hour = 18 + rand() % 7;
			if (hour == 18)
			{
				minute = 1 + rand() % 59;
			}
			else if (hour == 24)
			{
				minute = 0;
				hour = 0;
			}
			strcpy(part_of_day, "Evening");
			break;

		default:
			printf("Unknown choice entered.\n");
			return EXIT_FAILURE;
	}

	printf("Random time in the %s: %02d:%02d%s.\n", part_of_day, hour, minute, hour < 12 ? "am" : "pm");

	return EXIT_SUCCESS;
}
