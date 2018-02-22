/**
 * Exercise 2 – Half Pyramid
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


void print_half_pyramid(int height)
{
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
}


void print_full_pyramid(int height)
{
	int width = height * 2 - 1;
	for (int i = 1; i <= height; i++)
	{
		int current_width = i * 2 - 1;
		int empty = (width - current_width) / 2;
		for (int j = 1; j <= width; j++)
		{
			if (empty && (j - empty < 1 || j + empty > width))
			{
				putchar(' ');
			}
			else
			{
				putchar('*');
			}
		}
		putchar('\n');
	}
}


void print_full_temple(int height, int cap)
{
	int width = height * 2 - 1;
	for (int i = 1; i <= height; i++)
	{
		int current_width = i * 2 - 1;
		if (current_width < cap)
		{
			continue;
		}

		int empty = (width - current_width) / 2;
		for (int j = 1; j <= width; j++)
		{
			if (empty && (j - empty < 1 || j + empty > width))
			{
				putchar(' ');
			}
			else
			{
				putchar('*');
			}
		}
		putchar('\n');
	}
}


int main()
{
	print_half_pyramid(16);
	print_full_pyramid(32);
	print_full_temple(16, 8);

	return EXIT_SUCCESS;
}
