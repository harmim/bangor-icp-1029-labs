/**
 * Exercise 1 - Filled Square, Circle, Triangle
 * Exercise 2 – Outline and Shadow
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
	ALLEGRO_DISPLAY *display = create_display(600, 300);
	if (!display)
	{
		return EXIT_FAILURE;
	}

	al_clear_to_color(al_map_rgb(90, 90, 90));

	float start_x = 150.0, start_y = 150.0, size = 220.0, shadow_offset = 30, outline = 10;

	// rectangle
	al_draw_filled_rectangle(
		start_x + shadow_offset,
		start_y + shadow_offset,
		start_x + size + shadow_offset,
		start_y + size + shadow_offset,
		al_map_rgb(60, 60, 60)
	);
	al_draw_filled_rectangle(
		start_x - outline,
		start_y - outline,
		start_x + size + outline,
		start_y + size + outline,
		al_map_rgb(0, 0, 0)
	);
	al_draw_filled_rectangle(start_x, start_y, start_x + size, start_y + size, al_map_rgb(255, 0, 0));

	// circle
	float circle_r = size / 2, circle_offset = 440.0;
	al_draw_filled_circle(
		start_x + circle_offset + shadow_offset,
		start_y + circle_r + shadow_offset,
		circle_r,
		al_map_rgb(60, 60, 60)
	);
	al_draw_filled_circle(
		start_x + circle_offset,
		start_y + circle_r,
		circle_r + outline,
		al_map_rgb(0, 0, 0)
	);
	al_draw_filled_circle(start_x + circle_offset, start_y + circle_r, circle_r, al_map_rgb(0, 0, 255));

	// triangle
	float triangle_offset = 600.0;
	al_draw_filled_triangle(
		start_x + triangle_offset + shadow_offset,
		start_y + shadow_offset,
		start_x + triangle_offset + size + shadow_offset,
		start_y + shadow_offset,
		start_x + triangle_offset + size + shadow_offset,
		start_y + size + shadow_offset,
		al_map_rgb(60, 60, 60)
	);
	al_draw_filled_triangle(
		(float) (start_x + triangle_offset - 2.5 * outline),
		start_y - outline,
		start_x + triangle_offset + size + outline,
		start_y - outline,
		start_x + triangle_offset + size + outline,
		(float) (start_y + size + 2.5 * outline),
		al_map_rgb(0, 0, 0)
	);
	al_draw_filled_triangle(
		start_x + triangle_offset,
		start_y,
		start_x + triangle_offset + size,
		start_y,
		start_x + triangle_offset + size,
		start_y + size,
		al_map_rgb(0, 255, 0)
	);

	al_flip_display();
	al_rest(5.0);
	al_destroy_display(display);

	return EXIT_SUCCESS;
}
