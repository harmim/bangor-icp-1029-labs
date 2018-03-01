/**
 * Exercise 3 – Address mystery
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


void foo1(int x_val)
{
	int x = x_val;
	printf("foo1, x address: %#x, x value: %d\n", (unsigned int) &x, x);
}


void foo2(int y_val)
{
	int y = y_val;
	printf("foo2, y address: %#x, y value: %d\n", (unsigned int) &y, y);
}


int main()
{
	foo1(5);
	foo2(10);

	return EXIT_SUCCESS;
}
