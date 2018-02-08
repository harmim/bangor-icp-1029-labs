/**
 * Exercise 7 - Leap Years
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_leap_year(int year)
{
	if (year % 4 != 0)
	{
		return false;
	}

	if (year % 100 == 0 && year % 400 != 0)
	{
		return false;
	}

	return true;
}


int main()
{
	printf("Please enter a year: ");
	int year;
	scanf("%d", &year);

	printf("Year %d %s leap year.\n", year, is_leap_year(year) ? "is" : "is not");

	return EXIT_SUCCESS;
}
