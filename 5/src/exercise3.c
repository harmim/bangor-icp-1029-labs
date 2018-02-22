/**
 * Exercise 3 – Random Names
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


const char *forenames[] =
{
	"Betty",
	"Chet",
	"Daris",
	"Demi",
	"Evan",
	"Hannah",
	"Holly",
	"Iris",
	"Jerry",
	"Kate",
	"Kristy",
	"Lianne",
	"Louise",
	"Mindy",
	"Osbert",
	"Philip",
	"Reynold",
	"Sharon",
	"Tracy",
	"Velma",
};

const char *surnames[] =
{
	"Smith",
	"Jones",
	"Daris",
	"Williams",
	"Taylor",
	"Brown",
	"Davies",
	"Evans",
	"Wilson",
	"Thomas",
	"Johnson",
	"Roberts",
	"Robinson",
	"Thompson",
	"Wright",
	"Walker",
	"White",
	"Edwards",
	"Hughes",
	"Green",
};

const char *nicknames[] =
{
	"Bake",
	"Bee",
	"Bing",
	"Blondie",
	"Boom",
	"Butch",
	"Cobra",
	"Cats Eyes",
	"Dutch",
	"Ginger",
	"Hoppy",
	"Jumbo",
	"Pappy",
	"Skeeter",
	"Skinny",
	"Cowboy",
	"Cloudy",
	"The Black Devi",
	"Blackie",
	"Assi",
};


void generate_random_name(char *random_name)
{
	strcat(random_name, forenames[rand() % 20]);

	int nickname_random = rand();
	if (nickname_random % 100 < 30)
	{
		strcat(random_name, " \"");
		strcat(random_name, nicknames[nickname_random % 20]);
		strcat(random_name, "\"");
	}

	strcat(random_name, " ");
	strcat(random_name, surnames[rand() % 20]);
}


int main()
{
	srand((unsigned int) time(NULL));

	for (int i = 0; i < 10; i++)
	{
		char random_name[256] = {0};
		generate_random_name(random_name);
		printf("%s\n", random_name);
	}

	return EXIT_SUCCESS;
}
