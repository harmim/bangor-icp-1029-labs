/**
 * Exercise 5: Broken Circle
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.14159265359


int main()
{
	float radius;
	printf("---------------------------\n");
	printf(" ~~~ Circle Calculator ~~~ \n");
	printf("---------------------------\n");
	printf("Enter the Radius: ");
	scanf("%f", &radius);

	printf("Diameter is: %g\n", 2 * radius);
	printf("Circumference is: %.2f\n", 2 * PI * radius);
	printf("Area is: %.2f\n", PI * pow(radius, 2));

	return EXIT_SUCCESS;
}
