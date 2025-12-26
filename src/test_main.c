#include "../YY.utest/utest.h"
#include "image.h"
#include "fractal.h"

/*
 * Test basic image operations
 */
UTEST(Image, SetGet)
{
	image_p img = create_image(10, 10);

	set_pixel(img, 3, 3, 123);
	ASSERT_EQ(123, get_pixel(img, 3, 3));

	free_image(img);
}

UTEST(Image, Clear)
{
	image_p img = create_image(10, 10);

	set_pixel(img, 2, 2, 200);
	clear_image(img);

	ASSERT_EQ(0, get_pixel(img, 2, 2));

	free_image(img);
}

/*
 * Test image dimensions
 */
UTEST(Image, Dimensions)
{
	image_p img = create_image(640, 480);

	ASSERT_EQ(640u, image_width(img));
	ASSERT_EQ(480u, image_height(img));

	free_image(img);
}

/*
 * Test boundary pixel access
 */
UTEST(Image, BoundaryPixels)
{
	image_p img = create_image(100, 100);

	/* Set the four corner pixels */
	set_pixel(img, 0, 0, 10);
	set_pixel(img, 99, 0, 20);
	set_pixel(img, 0, 99, 30);
	set_pixel(img, 99, 99, 40);

	ASSERT_EQ(10, get_pixel(img, 0, 0));
	ASSERT_EQ(20, get_pixel(img, 99, 0));
	ASSERT_EQ(30, get_pixel(img, 0, 99));
	ASSERT_EQ(40, get_pixel(img, 99, 99));

	free_image(img);
}

/*
 * Test basic Mandelbrot set functionality
 */
UTEST(Fractal, MandelbrotBasic)
{
	image_p img = create_image(100, 100);

	mandelbrot_fractal(img);

	/* Check whether valid pixel values were generated (0–255) */
	pixel_data center = get_pixel(img, 50, 50);
	ASSERT_LE(center, 255);
	ASSERT_GE(center, 0);

	/* Check corner pixel values */
	pixel_data corner = get_pixel(img, 0, 0);
	ASSERT_LE(corner, 255);
	ASSERT_GE(corner, 0);

	free_image(img);
}

/*
 * Test basic Sierpinski carpet functionality
 */
UTEST(Fractal, SierpinskiBasic)
{
	image_p img = create_image(81, 81);

	sierpinski_fractal(img);

	/*
	 * The Sierpinski carpet should be a black-and-white image
	 */
	pixel_data center = get_pixel(img, 40, 40);
	ASSERT_TRUE(center == 0 || center == 255);

	/* Check corner area */
	pixel_data corner = get_pixel(img, 0, 0);
	ASSERT_TRUE(corner == 0 || corner == 255);

	free_image(img);
}

/*
 * Test empty fractal function
 */
UTEST(Fractal, EmptyFractal)
{
	image_p img = create_image(50, 50);

	set_pixel(img, 25, 25, 100);
	set_pixel(img, 10, 10, 200);

	empty_fractal(img);

	ASSERT_EQ(0, get_pixel(img, 25, 25));
	ASSERT_EQ(0, get_pixel(img, 10, 10));

	free_image(img);
}


/*
* Test basic behavior of Julia set generation
*/
UTEST(Fractal, JuliaSetBasic)
{
	image_p img = create_image(100, 100);

	/* Classic Julia set parameter */
	julia_fractal(img, -0.7, 0.27015);

	pixel_data center = get_pixel(img, 50, 50);
	ASSERT_LE(center, 255);
	ASSERT_GE(center, 0);

	/* Generate Mandelbrot set for comparison */
	image_p img2 = create_image(100, 100);
	mandelbrot_fractal(img2);

	pixel_data julia_center = get_pixel(img, 50, 50);
	pixel_data mandel_center = get_pixel(img2, 50, 50);

	printf("Julia center: %d, Mandelbrot center: %d\n",
		julia_center, mandel_center);

	free_image(img);
	free_image(img2);
}


UTEST_MAIN();
