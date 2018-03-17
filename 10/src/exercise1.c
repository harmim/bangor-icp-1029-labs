/**
 * Exercise 1 - Island Tours
 * Challenge - Island Tours database
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct
{
	char *name;
	float price;
} List_data;

typedef struct list_element
{
	List_data *data;
	struct list_element *left;
	struct list_element *right;
} List_element;

typedef struct
{
	List_element *first;
	List_element *last;
	List_element *active;
	int count;
} List;


void malloc_error()
{
	fprintf(stderr, "Memory allocation error.\n");
}


List_data *list_data_create(char *name, float price)
{
	List_data *data = (List_data *) malloc(sizeof(List_data));
	if (!data)
	{
		malloc_error();
		return NULL;
	}

	data->name = (char *) malloc(strlen(name) * sizeof(char));
	if (!data->name)
	{
		free(data);
		malloc_error();
		return NULL;
	}

	strcpy(data->name, name);
	data->price = price;

	return data;
}


void list_data_dispose(List_data *data)
{
	free(data->name);
	free(data);
}


List *list_create()
{
	List *list = (List *) malloc(sizeof(List));
	if (!list)
	{
		malloc_error();
		return NULL;
	}

	list->first = list->last = list->active = NULL;
	list->count = 0;

	return list;
}


void list_dispose(List *list)
{
	List_element *element;
	while ((element = list->first))
	{
		list->first = element->right;
		list_data_dispose(element->data);
		free(element);
	}

	free(list);
}


bool list_insert_last(List *list, List_data *data)
{
	List_element *element = (List_element *) malloc(sizeof(List_element));
	if (!element)
	{
		malloc_error();
		return false;
	}

	element->data = data;
	element->right = NULL;
	element->left = list->last;

	if (list->last)
	{
		list->last->right = element;
	}
	else
	{
		list->first = element;
	}
	list->last = element;
	list->count++;

	return true;
}


void list_delete_first(List *list)
{
	List_element *first = list->first;
	if (first)
	{
		if (first == list->active)
		{
			list->active = NULL;
		}

		if (first == list->last)
		{
			list->last = NULL;
		}
		else
		{
			first->right->left = NULL;
		}

		list->first = first->right;
		free(first);
		list->count--;
	}
}


void list_post_delete(List *list)
{
	if (list->active && list->active != list->last)
	{
		List_element *element = list->active->right;
		list->active->right = element->right;
		if (element == list->last)
		{
			list->last = list->active;
		}
		else
		{
			element->right->left = list->active;
		}
		free(element);
		list->count--;
	}
}


void list_swap(List *list, int old_position, int new_position)
{
	if (old_position >= 0 && old_position < list->count && new_position >= 0 && new_position < list->count)
	{
		List_element *old = NULL, *new = NULL, *element = list->first;
		for (int i = 0; element; element = element->right, i++)
		{
			if (i == old_position)
			{
				old = element;
			}
			if (i == new_position)
			{
				new = element;
			}
		}

		List_data *tmp = old->data;
		old->data = new->data;
		new->data = tmp;
	}
}


void list_first(List *list)
{
	list->active = list->first;
}


void list_next(List *list)
{
	if (list->active)
	{
		list->active = list->active->right;
	}
}


bool list_active(List *list)
{
	return list->active != NULL;
}


List_data *list_get_data(List *list)
{
	if (!list->active)
	{
		return NULL;
	}

	return list->active->data;
}


int get_position(const char *label, List *list)
{
	printf("%s: ", label);
	int position;
	scanf("%d", &position);

	if (position < 1 || position > list->count)
	{
		fprintf(stderr, "Unknown position.\n");
		return -1;
	}

	return position;
}


int main()
{
	List *list = list_create();
	if (!list)
	{
		return EXIT_FAILURE;
	}

	printf("Island Tours\n");

	const int max_name_length = 256;
	char name[max_name_length];
	bool exit = false, error = false;
	do
	{
		printf("\n%-10s %-40s %-20s\n", "Position", "Island", "Entry Price");
		printf("%-10s %-40s %-20s\n", "--------", "------", "-----------");
		int i;
		for (i = 1, list_first(list); list_active(list); list_next(list), i++)
		{
			List_data *data = list_get_data(list);
			printf("%-10d %-40s %-20g\n", i, data->name, data->price);
		}
		printf("%-10s %-40s %-20s\n\n", "--------", "------", "-----------");

		printf(
			"1. Insert island\n"
			"2. Delete island\n"
			"3. Modify order of islands\n"
			"4. Exit\n\n"
			"Enter choice: "
		);
		int choice;
		scanf("%d", &choice);
		getchar();
		putchar('\n');
		switch (choice)
		{
			case 1:
				printf("Name: ");
				fgets(name, max_name_length, stdin);
				char *new_line = strchr(name, '\n');
				if (new_line)
				{
					*new_line = '\0';
				}

				printf("Price: ");
				float price;
				scanf("%f", &price);

				List_data *data = list_data_create(name, price);
				if (!data || !list_insert_last(list, data))
				{
					error = exit = true;
				}
				break;

			case 2:
				if (list->count == 0)
				{
					break;
				}
				int position = get_position("Position", list);
				if (position == -1)
				{
					error = exit = true;
					break;
				}

				if (position == 1)
				{
					list_delete_first(list);
				}
				else
				{
					for (i = 1, list_first(list); list_active(list); list_next(list), i++)
					{
						if (position == i + 1)
						{
							list_post_delete(list);
							break;
						}
					}
				}
				break;

			case 3:
				if (list->count == 0)
				{
					break;
				}
				int old_position = get_position("Old position", list);
				if (old_position == -1)
				{
					error = exit = true;
					break;
				}
				int new_position = get_position("New position", list);
				if (new_position == -1)
				{
					error = exit = true;
					break;
				}

				list_swap(list, old_position - 1, new_position - 1);
				break;

			case 4:
				exit = true;
				break;

			default:
				fprintf(stderr, "Unknown choice.\n");
				error = exit = true;
		}
	}
	while (!exit);

	list_dispose(list);

	return error ? EXIT_FAILURE : EXIT_SUCCESS;
}
