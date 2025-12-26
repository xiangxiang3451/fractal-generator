#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* 8-bit grayscale pixel */
typedef uint8_t pixel_data;

/* pixel coordinate / dimension */
typedef unsigned int pixel_coord;

struct image;
typedef struct image image_t, * image_p;

/**
 * Create new image (allocated on heap)
 */
image_p create_image(pixel_coord width, pixel_coord height);

void fill_random(image_p picture);
void clear_image(image_p picture);
void free_image(image_p picture);

/**
 * Accessors — hide struct internals
 */
pixel_coord image_width(image_p picture);
pixel_coord image_height(image_p picture);

/**
 * Save as ASCII PGM (debug)
 */
int save_pgm(image_p picture, const char* filename);

/**
 * Save as binary PGM (P5)
 */
int save_pgm_binary(image_p picture, const char* filename);

/**
 * Pixel operations
 */
void set_pixel(image_p picture, pixel_coord x, pixel_coord y, pixel_data color);
pixel_data get_pixel(image_p picture, pixel_coord x, pixel_coord y);

#endif /* _IMAGE_H_ */
