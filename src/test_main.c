#include "../YY.utest/utest.h"
#include "image.h"

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

UTEST_MAIN();
