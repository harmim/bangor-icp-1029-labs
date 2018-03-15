/**
 * Dot Spiral
 * Line Spiral
 * Fading Spiral
 * Multiple Spirals
 *
 * @author Dominik Harmim <harmim6@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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


/**
 * Draws dots spiral.
 *
 * @param c_x center X coordination
 * @param c_y center Y coordination
 * @param color dots color
 * @param number_of_points number of points to draw
 * @param degree degree change in angle between each step
 * @param tightness tightness
 */
void draw_dot_spiral(float c_x, float c_y, ALLEGRO_COLOR color, int number_of_points, float degree, float tightness)
{
	for (int i = 0; i < number_of_points; i++)
	{
		float angle = degree * i,
			x = (1 + angle) * cosf(angle * tightness),
			y = (1 + angle) * sinf(angle * tightness);

		al_draw_filled_circle(c_x + x, c_y + y, 5, color);
	}
}


/**
 * Draws line spiral.
 *
 * @param c_x center X coordination
 * @param c_y center Y coordination
 * @param start_color line start color
 * @param end_color line end color
 * @param number_of_points number of lines to draw - 1
 * @param degree degree change in angle between each step
 * @param tightness tightness
 * @param thickness thickness
 */
void draw_line_spiral(
	float c_x,
	float c_y,
	ALLEGRO_COLOR start_color,
	ALLEGRO_COLOR end_color,
	int number_of_points,
	float degree,
	float tightness,
	float thickness
)
{
	float prev_x = 0.0, prev_y = 0.0;
	for (int i = 0; i < number_of_points; i++)
	{
		float angle = degree * i,
			x = (1 + angle) * cosf(angle * tightness),
			y = (1 + angle) * sinf(angle * tightness);

		if (i != 0)
		{
			float end_color_coeff = (i + 1) / (float) number_of_points,
				start_color_coeff = 1 - end_color_coeff;
			ALLEGRO_COLOR color = al_map_rgb_f(
				start_color.r * start_color_coeff + end_color.r * end_color_coeff,
				start_color.g * start_color_coeff + end_color.g * end_color_coeff,
				start_color.b * start_color_coeff + end_color.b * end_color_coeff
			);
			al_draw_line(c_x + prev_x, c_y + prev_y, c_x + x, c_y + y, color, thickness);
		}

		prev_x = x;
		prev_y = y;
	}
}


int main()
{
	int width = 400, height = 400;
	ALLEGRO_DISPLAY *display = create_display(width, height);
	if (!display)
	{
		return EXIT_FAILURE;
	}

	ALLEGRO_COLOR color;

	al_clear_to_color(al_map_rgb(0, 0, 0));
	draw_dot_spiral(width, height, al_map_rgb(200, 0, 0), 1000, 0.4, 0.2);
	al_flip_display();
	al_rest(3.0);

	al_clear_to_color(al_map_rgb(0, 0, 0));
	draw_line_spiral(width, height, al_map_rgb(200, 0, 0), al_map_rgb(0, 0, 0), 1000, 0.4, 0.2, 8.0);
	al_flip_display();
	al_rest(3.0);

	al_clear_to_color(al_map_rgb(30, 30, 30));
	color = al_map_rgb(130, 250, 140);
	draw_line_spiral(width / 2, height / 2, color, color, 180, 1, 0.2, 10);
	color = al_map_rgb(230, 150, 255);
	draw_line_spiral(width / 2 + width, height / 2, color, color, 180, 1, 0.2, 10);
	color = al_map_rgb(232, 124, 34);
	draw_line_spiral(width / 2, height / 2 + height, color, color, 180, 1, 0.2, 10);
	color = al_map_rgb(255, 240, 47);
	draw_line_spiral(width / 2 + width, height / 2 + height, color, color, 180, 1, 0.2, 10);
	al_flip_display();
	al_rest(3.0);

	al_clear_to_color(al_map_rgb(51, 9, 198));
	draw_line_spiral(width, height, al_map_rgb(255, 255, 255), al_map_rgb(169, 1, 192), 800, 0.4, 0.2, 8.0);
	al_flip_display();
	al_rest(3.0);

	al_clear_to_color(al_map_rgb(255, 255, 255));
	color = al_map_rgb(0, 0, 0);
	draw_line_spiral(width, height, color, color, 1000, 2.0, 0.55, 15.0);
	color = al_map_rgb(130, 250, 140);
	draw_line_spiral(width, height, color, color, 1000, 2.0, 0.55, 5.0);
	al_flip_display();
	al_rest(3.0);

	al_destroy_display(display);

	return EXIT_SUCCESS;
}
