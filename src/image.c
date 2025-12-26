#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "image.h"

struct image
{
	pixel_coord width;
	pixel_coord height;
	pixel_data* data;
};

image_p create_image(pixel_coord width, pixel_coord height)
{
	assert(width > 0 && height > 0);

	image_t* img = malloc(sizeof(image_t));
	assert(img != NULL);

	img->width = width;
	img->height = height;
	img->data = malloc(sizeof(pixel_data) * width * height);
	assert(img->data != NULL);

	clear_image(img);
	return img;
}

void clear_image(image_p picture)
{
	memset(picture->data, 0,
		sizeof(pixel_data) * picture->width * picture->height);
}

void fill_random(image_p picture)
{
	for (pixel_coord i = 0; i < picture->width * picture->height; ++i)
		picture->data[i] = (pixel_data)(rand() % 256);
}

void free_image(image_p picture)
{
	assert(picture != NULL);
	free(picture->data);
	free(picture);
}

/* --- Accessors --- */
pixel_coord image_width(image_p picture)
{
	return picture->width;
}

pixel_coord image_height(image_p picture)
{
	return picture->height;
}

/* --- ASCII PGM P2 (debug) --- */
int save_pgm(image_p picture, const char* filename)
{
	FILE* fp = fopen(filename, "w");
	assert(fp != NULL);

	fprintf(fp, "P2\n%u %u\n255\n",
		picture->width, picture->height);

	for (pixel_coord i = 0; i < picture->width * picture->height; ++i)
		fprintf(fp, "%u ", picture->data[i]);

	fclose(fp);
	return 0;
}

/* --- Binary PGM P5 --- */
int save_pgm_binary(image_p picture, const char* filename)
{
	FILE* fp = fopen(filename, "wb");
	assert(fp != NULL);

	fprintf(fp, "P5\n%u %u\n255\n",
		picture->width, picture->height);

	fwrite(picture->data,
		sizeof(pixel_data),
		picture->width * picture->height,
		fp);

	fclose(fp);
	return 0;
}

/* --- Pixel API --- */
void set_pixel(image_p picture, pixel_coord x, pixel_coord y, pixel_data color)
{
	assert(x < picture->width && y < picture->height);
	picture->data[y * picture->width + x] = color;
}

pixel_data get_pixel(image_p picture, pixel_coord x, pixel_coord y)
{
	assert(x < picture->width && y < picture->height);
	return picture->data[y * picture->width + x];
}
