/**
 * Exercise 3 – Checkerboard
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


/**
 * Initializes Allegro, creates display and initializes primitives addon.
 *
 * @param width display width
 * @param height display height
 * @return created display or NULL in case of error
 */
ALLEGRO_DISPLAY *create_display(int width, int height)
{
	if (!al_init())
	{
		fprintf(stderr, "Failed to initialize Allegro.\n");
		return NULL;
	}

	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "Failed to initialize Allegro primitives addon.\n");
		return NULL;
	}

	ALLEGRO_DISPLAY *display = al_create_display(width, height);
	if (!display)
	{
		fprintf(stderr, "Failed to create display.\n");
		return NULL;
	}

	return display;
}


int main()
{
	int width = 300, height = 300;
	ALLEGRO_DISPLAY *display = create_display(width, height);
	if (!display)
	{
		return EXIT_FAILURE;
	}

	int number_of_squares_in_row = 8;
	float square_size = 2 * ((float) width / number_of_squares_in_row);
	ALLEGRO_COLOR color, black = al_map_rgb(0, 0, 0), white = al_map_rgb(255, 255, 255);

	for (int row = 0; row < number_of_squares_in_row; row++)
	{
		float y = square_size * row;
		for (int col = 0; col < number_of_squares_in_row; col++)
		{
			float x = square_size * col;

			if (row % 2 == col % 2)
			{
				color = white;
			}
			else
			{
				color = black;
			}

			al_draw_filled_rectangle(x, y, x + square_size, y + square_size, color);
		}
	}

	al_flip_display();
	al_rest(5.0);
	al_destroy_display(display);

	return EXIT_SUCCESS;
}
