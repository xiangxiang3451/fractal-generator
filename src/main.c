#include "image.h"
#include "fractal.h"

int main()
{
	image_p img = create_image(600, 600);

	mandelbrot_fractal(img);
	save_pgm_binary(img, "mandelbrot.pgm");

	sierpinski_fractal(img);
	save_pgm_binary(img, "sierpinski.pgm");

	julia_fractal(img, -0.7, 0.27015);
	save_pgm_binary(img, "julia_classic.pgm");

	julia_fractal(img, -0.7269, 0.1889);
	save_pgm_binary(img, "julia_spiral.pgm");

	free_image(img);
	return 0;
}
