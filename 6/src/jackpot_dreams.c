/**
 * Jackpot Dreams
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define LOTTO_NUMBERS_COUNT 6 /// number of lottery numbers
#define WEEKS_IN_YEAR 52 /// number of weeks in year


/**
 * Lucky lottery numbers. (Must be unique.)
 */
const int lucky_numbers[LOTTO_NUMBERS_COUNT] = {5, 11, 15, 33, 42, 43};


/**
 * Creates an array of n random unique lottery numbers 1-49.
 *
 * @param draw rusulting array with random unique lottery number
 * @param count number of random numbers to generate
 */
void get_lotto_draw(int *draw, int count)
{
	for (int i = 0; i < count;)
	{
		bool unique = true;
		int random_number = ((int) random()) % 49 + 1;

		for (int j = 0; j < i; j++)
		{
			if (draw[j] == random_number)
			{
				unique = false;
				break;
			}
		}

		if (unique)
		{
			draw[i] = random_number;
			i++;
		}
	}
}


/**
 * Prints out the content of an array of given length.
 *
 * @param array array to print out
 * @param length length of given array
 */
void print_array(const int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d", array[i]);
		if (i != length - 1)
		{
			putchar(' ');
		}
	}
	putchar('\n');
}


/**
 * Returns number of matches between two arrays.
 *
 * @param array1 first array to compare
 * @param array2 second array to compare
 * @param length length of arrays
 * @return number of matches between two arrays
 */
int find_matches(const int *array1, const int *array2, int length)
{
	int matches = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (array1[i] == array2[j])
			{
				matches++;
			}
		}
	}

	return matches;
}


/**
 * Prints welcome message.
 */
void print_welcome_message()
{
	printf(
		"-----------------------------\n"
		"   Project: Jackpot Dreams   \n"
		"-----------------------------\n\n"
	);
}


/**
 * Prints starting message.
 *
 * @param years_to_sleep number of years to sleep
 * @param account_balance bank account balance
 */
void print_starting_message(long long int years_to_sleep, long long int account_balance)
{
	printf(
		"\nOK. I will now play the lottery for %lld %s.\n"
		"Bank account balance: £%lld.\n"
		"Sweet dreams...\n\n"
		"-----------------------------\n\n",
		years_to_sleep,
		years_to_sleep == 1 ? "year" : "years",
		account_balance
	);
}


/**
 * Prints lottery result.
 *
 * @param won tells whether lottery has been won or not
 * @param year year after lottery playing
 * @param account_balance bank account balance
 */
void print_result(bool won, long long int year, long long int account_balance)
{
	if (won)
	{
		printf("Matched the lottery numbers: ");
		print_array(lucky_numbers, LOTTO_NUMBERS_COUNT);
		printf(
			"Wake up Roger! It's the year %lld. You've won the lottery!!\n"
			"Bank account balance: £%lld.\n\n",
			year,
			account_balance
		);
	}
	else
	{
		printf(
			"Wake up Roger! It's the year %lld.\n"
			"Bank account balance: £%lld.\n\n",
			year,
			account_balance
		);
	}
}


/**
 * Prints matched numbers.
 *
 * @param matched matched numbers
 */
void print_matched_numbers(const long long int *matched)
{
	for (int i = 0; i <= LOTTO_NUMBERS_COUNT; i++)
	{
		printf("Matched %d %s %lld times.\n", i, i == 0 ? "number" : "numbers", matched[i]);
	}
}


/**
 * Gets number of years to sleep.
 *
 * @return number of years to sleep or -1 in case of error
 */
long long int get_years_to_sleep()
{
	printf("How many years to sleep? ");
	long long int years_to_sleep;
	scanf("%lld", &years_to_sleep);

	if (years_to_sleep <= 0)
	{
		printf("\nNumber of years must be positive number greater than zero.\n");
		return -1;
	}

	return years_to_sleep;
}


/**
 * Returns current year + number of elapsed years.
 *
 * @param years_elapsed number of elapsed years
 * @return current year + number of elapsed years
 */
long long int get_year(long long int years_elapsed)
{
	time_t current_time;
	time(&current_time);
	struct tm current_time_struct = *gmtime(&current_time);

	return current_time_struct.tm_year + 1900 + years_elapsed;
}


/**
 * Plays lottery.
 * Finds numbers of matches, gets years elapsed, tells whether wins or not and modifies account balance.
 *
 * @param years_to_sleep number of years to sleep
 * @param matched returns numbers of matches
 * @param years_elapsed returns number of years elapsed
 * @param account_balance modifies account balance
 * @return tells whether lottery has been won or not
 */
bool play_lottery(
	long long int years_to_sleep,
	long long int *matched,
	long long int *years_elapsed,
	long long int *account_balance
)
{
	int lotto_draw[LOTTO_NUMBERS_COUNT];

	for (*years_elapsed = 0; *years_elapsed < years_to_sleep; (*years_elapsed)++)
	{
		for (int i = 0; i < WEEKS_IN_YEAR; i++)
		{
			*account_balance -= 2;

			get_lotto_draw(lotto_draw, LOTTO_NUMBERS_COUNT);
			int matches = find_matches(lucky_numbers, lotto_draw, LOTTO_NUMBERS_COUNT);
			matched[matches]++;

			switch (matches)
			{
				case 3:
					*account_balance += 25;
					break;

				case 4:
					*account_balance += 100;
					break;

				case 5:
					*account_balance += 1000;
					break;

				case 6:
					*account_balance += 2000000;
					break;

				default:
					// doesn't win anything
					break;
			}

			if (matches == LOTTO_NUMBERS_COUNT)
			{
				return true;
			}
		}
	}

	return false;
}


/**
 * Main function.
 *
 * @return EXIT_SUCCESS in case of no error, EXIT_FAILURE otherwise
 */
int main()
{
	srandom((unsigned int) time(NULL));

	print_welcome_message();

	long long int years_to_sleep = get_years_to_sleep();
	if (years_to_sleep == -1)
	{
		return EXIT_FAILURE;
	}

	long long int account_balance = 10000;
	print_starting_message(years_to_sleep, account_balance);

	long long int matched[LOTTO_NUMBERS_COUNT + 1] = {0}, years_elapsed;
	print_result(
		play_lottery(years_to_sleep, matched, &years_elapsed, &account_balance),
		get_year(years_elapsed),
		account_balance
	);

	print_matched_numbers(matched);

	return EXIT_SUCCESS;
}
