/**
 * Exercise 1: Say Hello
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
	char card[] =
		"|---------------------------------------------|\n"
		"|               Dominik Harmim                |\n"
		"|---------------------------------------------|\n"
		"|      Age: 20                                |\n"
		"|      Occupation: Student                    |\n"
		"|      Height: 1.83 m                         |\n"
		"|      Eyes: Brown                            |\n"
		"|      First Computer: Pentium III            |\n"
		"|---------------------------------------------|\n";

	printf("%s", card);

	return EXIT_SUCCESS;
}
