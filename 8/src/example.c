/**
 * Example Allegro usage
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h> // main Allegro header file
#include <allegro5/allegro_primitives.h> // primitive header file


/**
 * Initializes Allegro, creates display and initializes primitives addon.
 *
 * @param width display width
 * @param height display height
 * @return created display or NULL in case of error
 */
ALLEGRO_DISPLAY *create_display(int width, int height)
{
	// initialize Allegro
	if (!al_init())
	{
		fprintf(stderr, "Failed to initialize Allegro.\n");
		return NULL;
	}

	// initialize the use of primitives
	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "Failed to initialize Allegro primitives addon.\n");
		return NULL;
	}

	// the Allegro display variable - allows us to render to a window
	// create the display window, set the resolution to width by height
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
	ALLEGRO_DISPLAY *display = create_display(640, 480);
	if (!display)
	{
		return EXIT_FAILURE;
	}

	// set the back buffer to a light blue color (red, green, blue)
	al_clear_to_color(al_map_rgb(100, 100, 255));

	// draw circle
	al_draw_circle(300.0, 300.0, 150.0, al_map_rgb(0, 0, 255), 8.0);

	// draw rectangle
	float square_pos[2] = {200.0, 300.0}; // store x,y coords for square
	float square_size = 100.0;
	al_draw_filled_rectangle(
		square_pos[0],
		square_pos[1],
		square_pos[0] + square_size,
		square_pos[1] + square_size,
		al_map_rgb(255, 0, 0)
	);

	// flip buffer to show on screen
	al_flip_display();

	// rest for 5 seconds
	al_rest(5.0);

	// destroy display
	al_destroy_display(display);

	return EXIT_SUCCESS;
}
