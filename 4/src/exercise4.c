/**
 * Exercise 4 – Mock menu system
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


int main()
{
	bool quit = false;
	while (true)
	{
		printf(
			"     Main menu     \n\n"
			"1. Single Player\n"
			"2. Multiplayer\n"
			"3. Options\n"
			"4. Credits\n"
			"5. Quit\n\n"
			"Enter choice: "
		);

		int option;
		scanf("%d", &option);
		switch (option)
		{
			case 1:
				printf("\nSingle Player!\n");
				break;

			case 2:
				printf("\nMultiplayer!\n");
				break;

			case 3:
				printf("\nOptions!\n");
				break;

			case 4:
				printf("\nCredits!\n");
				break;

			case 5:
				quit = true;
				break;

			default:
				printf("Unknow choice entered.\n");
				return EXIT_FAILURE;
		}

		if (quit)
		{
			break;
		}

		sleep(1);
		printf("\n\n");
	}

	return EXIT_SUCCESS;
}
