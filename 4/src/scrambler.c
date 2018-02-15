/**
 * Scrambler
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


/**
 * Process and Scramble input string.
 */
void scramble()
{
	// gets string (max 255 chars) from stdin
	printf("Please enter your string: ");
	char string[256];
	fgets(string, 256, stdin);
	putchar('\n');

	char key_cypher[256] = {0};
	int key_cypher_end = 0;
	// repeat replacing chars of input string until sentinel character will be entered
	while (true)
	{
		printf("String is: %s\n\n", string);

		// gets target character
		printf("Target: ");
		char target = (char) getchar();
		getchar();
		// if target character is q or Q, exit this loop
		if (tolower(target) == 'q')
		{
			break;
		}

		// gets replace with character
		printf("Replace with: ");
		char replacement = (char) getchar();
		getchar();

		// checks if replacement character already isn't in input string, if it is then error will be printed
		bool error = false;
		for (int i = 0; string[i] != '\0'; i++)
		{
			if (string[i] == replacement)
			{
				error = true;
				printf("\nERROR - %c already exists in the string\n", replacement);
				break;
			}
		}
		if (error)
		{
			continue;
		}

		// replaces all occurrences of target character with replacement character
		printf("\nReplacing %c with %c\n", target, replacement);
		for (int i = 0; string[i] != '\0'; i++)
		{
			if (string[i] == target)
			{
				string[i] = replacement;
			}
		}

		// stores key cypher information
		key_cypher[key_cypher_end++] = target;
		key_cypher[key_cypher_end++] = replacement;
		key_cypher[key_cypher_end++] = ' ';
	}

	// prints resulting Scrambled string and key cypher
	printf("\n\nSCRAMBLED STRING IS: %s\n", string);
	printf("Key Cypher: %s\n", key_cypher);
}


/**
 * Process and Unsramble input string.
 */
void unscramble()
{
	// gets string (max 255 chars) from stdin
	printf("Please enter your scrumbled string: ");
	char string[256];
	fgets(string, 256, stdin);

	// gets key cypher (max 255 chars) from stdin
	printf("Please enter your key cypher (pairs of chars separated by white spaces): ");
	char key_cypher[256];
	fgets(key_cypher, 256, stdin);

	// iterate over key cypher pairs
	for (int i = 0; key_cypher[i] != '\0'; i++)
	{
		// if current character is space, it will be skipped
		if (isspace(key_cypher[i]))
		{
			continue;
		}

		// iterate over string and replace all occurrences of second char from key cypher for first char
		for (int j = 0; string[j] != '\0'; j++)
		{
			if (string[j] == key_cypher[i + 1])
			{
				string[j] = key_cypher[i];
			}
		}

		i += 2; // move to the next pair in key_cypher
	}

	// prints resulting Unscrambled string
	printf("\n\nUNSCRAMBLED STRING IS: %s\n", string);
}


/**
 * Main function.
 *
 * @return EXIT_SUCCESS in case of no error, EXIT_FAILURE otherwise
 */
int main()
{
	// welcome message
	printf(
		"------------------------\n"
		"WELCOME TO THE SCRAMBLER\n"
		"------------------------\n\n"
		"1. Scramble\n"
		"2. Unscramble\n"
		"Enter choice: "
	);

	// choice processing (Scramble or Unsramble)
	int choice;
	scanf("%d", &choice);
	getchar();
	printf("\n\n");
	switch (choice)
	{
		case 1:
			// do Scramble
			scramble();
			break;

		case 2:
			// do Unscramble
			unscramble();
			break;

		default:
			// unknown option
			printf("Unknown choice entered.\n");
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
