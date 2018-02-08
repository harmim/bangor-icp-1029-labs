/**
 * Exercise 4 – Switch Grade did I get?
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("Please enter a grade (0-100): ");
	int grade;
	scanf("%d", &grade);

	if (grade > 100 || grade < 0)
	{
		printf("Invalid grade entered.\n");
		return EXIT_FAILURE;
	}

	switch (grade / 10)
	{
		case 10:
		case 9:
		case 8:
			printf("Grade A.\n");
			break;

		case 7:
			printf("Grade B.\n");
			break;

		case 6:
			printf("Grade C.\n");
			break;

		case 5:
			printf("Grade D.\n");
			break;

		case 4:
			printf("Grade E.\n");
			break;

		default:
			printf("Grade F.\n");
	}

	return EXIT_SUCCESS;
}
