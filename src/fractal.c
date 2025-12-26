#include "fractal.h"
#include <assert.h>
#include <stdbool.h>
#include <math.h>

void empty_fractal(image_p picture)
{
	clear_image(picture);
}

/* --- Mandelbrot --- */
void mandelbrot_fractal(image_p picture)
{
	assert(picture != NULL);

	pixel_coord W = image_width(picture);
	pixel_coord H = image_height(picture);

	for (pixel_coord y = 0; y < H; ++y)
		for (pixel_coord x = 0; x < W; ++x)
		{
			double cx = (x - W / 2.0) / (W / 4.0);
			double cy = (y - H / 2.0) / (H / 4.0);

			double zx = 0, zy = 0;
			int iter = 0, max_iter = 255;

			while (zx * zx + zy * zy <= 4 && iter < max_iter)
			{
				double t = zx * zx - zy * zy + cx;
				zy = 2 * zx * zy + cy;
				zx = t;
				++iter;
			}

			set_pixel(picture, x, y, (pixel_data)iter);
		}
}

/* --- Sierpinski carpet --- */
void sierpinski_fractal(image_p picture)
{
	assert(picture != NULL);

	clear_image(picture);

	pixel_coord W = image_width(picture);
	pixel_coord H = image_height(picture);

	for (pixel_coord y = 0; y < H; ++y)
		for (pixel_coord x = 0; x < W; ++x)
		{
			pixel_coord i = x, j = y;
			bool hole = false;

			while (i > 0 || j > 0)
			{
				if (i % 3 == 1 && j % 3 == 1)
				{
					hole = true;
					break;
				}
				i /= 3;
				j /= 3;
			}

			set_pixel(picture, x, y, hole ? 0 : 255);
		}
}

/* --- Julia Set --- */
void julia_fractal(image_p picture, double real_c, double imag_c)
{
	assert(picture != NULL);

	pixel_coord W = image_width(picture);
	pixel_coord H = image_height(picture);

	for (pixel_coord y = 0; y < H; ++y)
		for (pixel_coord x = 0; x < W; ++x)
		{
			double zx = (x - W / 2.0) / (W / 4.0);
			double zy = (y - H / 2.0) / (H / 4.0);

			int iter = 0, max_iter = 255;

			while (zx * zx + zy * zy <= 4 && iter < max_iter)
			{
				double t = zx * zx - zy * zy + real_c;
				zy = 2 * zx * zy + imag_c;
				zx = t;
				++iter;
			}

			set_pixel(picture, x, y, (pixel_data)iter);
		}
}
