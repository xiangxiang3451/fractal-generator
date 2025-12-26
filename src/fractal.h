#ifndef _FRACTAL_H_
#define _FRACTAL_H_

#include "image.h"


/*
 * Fractal generation functions.
 */

void empty_fractal(image_p picture);
void mandelbrot_fractal(image_p picture);
void sierpinski_fractal(image_p picture);
void julia_fractal(image_p picture, double real_c, double imag_c);


#endif /* _FRACTAL_H_ */
