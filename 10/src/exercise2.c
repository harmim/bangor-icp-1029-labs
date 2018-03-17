/**
 * Exercise 2 - Chatbot v0.2
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct node
{
	char *question;
	struct node *yes;
	struct node *no;
} Node;


int main()
{
	printf(
		"------------\n"
		"Chatbot v0.2\n"
		"------------\n\n"
	);

	Node node1 = {
		.question = "In 19th century Britain, sausages were marketed as \"bags of mystery\".",
		.yes = NULL,
		.no = NULL,
	};
	Node node2 = {
		.question = "Aaaaw. Come on, it'sa good one?",
		.yes = &node1,
		.no = NULL,
	};
	Node node3 = {
		.question = "Great. Listen, you want to know a fun fact?",
		.yes = &node1,
		.no = &node2,
	};
	Node node4 = {
		.question = "Maybe I tell you a fact that would cheer you up?",
		.yes = &node1,
		.no = NULL,
	};
	Node root = {
		.question = "Hello Friend. Are you happy today?",
		.yes = &node3,
		.no = &node4,
	};

	Node *node = &root;
	while (node)
	{
		if (!node->yes && !node->no)
		{
			printf("%s \n", node->question);
			break;
		}

		char decision[256];
		bool yes, no;
		do
		{
			printf("%s ", node->question);
			scanf("%255s", decision);
			getchar();
			yes = strcmp(decision, "yes") == 0;
			no = strcmp(decision, "no") == 0;
		}
		while (!yes && !no);

		if (yes)
		{
			node = node->yes;
		}
		else
		{
			node = node->no;
		}
	}

	return EXIT_SUCCESS;
}
