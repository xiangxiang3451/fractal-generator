#include "image.h"
#include "fractal.h"

int main()
{
	image_p img = create_image(600, 600);

	mandelbrot_fractal(img);
	save_pgm_binary(img, "mandelbrot.pgm");

	sierpinski_fractal(img);
	save_pgm_binary(img, "sierpinski.pgm");

	free_image(img);
	return 0;
}
