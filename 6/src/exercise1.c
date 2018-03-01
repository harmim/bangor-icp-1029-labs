/**
 * Exercise 1 – Pointer variables
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
	int var_int = 100;
	printf("var_int: %d\n", var_int);
	printf("address: %#x\n", (unsigned int) &var_int);
	printf("stored in %d bytes\n", (int) sizeof(var_int));
	putchar('\n');

	char var_char = 'a';
	printf("var_char: %c\n", var_char);
	printf("address: %#x\n", (unsigned int) &var_char);
	printf("stored in %d bytes\n", (int) sizeof(var_char));
	putchar('\n');

	float var_float = 3.12;
	printf("var_float: %g\n", var_float);
	printf("address: %#x\n", (unsigned int) &var_float);
	printf("stored in %d bytes\n", (int) sizeof(var_float));
	putchar('\n');

	printf("--------------------------\n\n");

	int *p_var_int = &var_int;
	printf("p_var_int: %d\n", *p_var_int);
	printf("address: %#x\n", (unsigned int) &p_var_int);
	printf("stored in %d bytes\n", (int) sizeof(p_var_int));
	putchar('\n');

	char *p_var_char = &var_char;
	printf("p_var_char: %c\n", *p_var_char);
	printf("address: %#x\n", (unsigned int) &p_var_char);
	printf("stored in %d bytes\n", (int) sizeof(p_var_char));
	putchar('\n');

	float *p_var_float = &var_float;
	printf("p_var_float: %g\n", *p_var_float);
	printf("address: %#x\n", (unsigned int) &p_var_float);
	printf("stored in %d bytes\n", (int) sizeof(p_var_float));
	putchar('\n');

	printf("--------------------------\n\n");

	return EXIT_SUCCESS;
}
