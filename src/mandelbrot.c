#include "fractol.h"

int mandelbrot_set(double c_re, double c_im)
{
	double z_re;
	double z_im;
	double tmp;
	int n;

	z_re = c_re;
	z_im = c_im;
	n = 0;
	while (n < 50)
	{
		if (z_re * z_re + z_im * z_im > 4)
			return (n);
		tmp = z_im;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re * z_re - (tmp * tmp) + c_re;
		n++;
	}
	return (-1);
}

int	mandelbrot(t_param *p)
{
	double minRe;
	double maxRe;
	double minIm;
	double maxIm;

	double c_re;
	double c_im;

	double k_re;
	double k_im;

	int y;
	int x;
	int n;
	minRe = -2.1 - p->zoomx;
	maxRe = 0.6 + p->zoomx;
	minIm = -1.2;
//	maxIm = 1;
	maxIm = minIm + ((maxRe - minRe) * HEIGHT - 1) / (WIDTH - 1);
	k_re = (maxRe - minRe) / WIDTH;
	k_im = (maxIm - minIm) / HEIGHT;

	y = 0;
	while (++y < HEIGHT)
	{
		c_im = maxIm - y * k_im;
		x = 0;
		while (++x < WIDTH)
		{
			c_re = minRe + x * k_re;
			if ((n = mandelbrot_set(c_re, c_im)) == -1 && (x + y * WIDTH) < WIDTH * HEIGHT)
				p->image[x + y * WIDTH] = WHITE;
			else if (n != 0 && (x + y * WIDTH) < WIDTH * HEIGHT)
				p->image[x + y * WIDTH] = BLACK + n * 10;
			/*else if (n < 10 && (x + y * WIDTH) < WIDTH * HEIGHT)
				p->image[x + y * WIDTH] = GREEN + n * 5;
			else if (n >= 10 && n < 20 && (x + y * WIDTH) < WIDTH * HEIGHT)
				p->image[x + y * WIDTH] = RED + n * 5;
			else if (n >= 20 && n < 35 && (x + y * WIDTH) < WIDTH * HEIGHT)
				p->image[x + y * WIDTH] = PURPLE + n * 5;
			else if (n >= 35 && n < 50 && (x + y * WIDTH) < WIDTH * HEIGHT)
				p->image[x + y * WIDTH] = BROWN + n * 5;*/
		}
	}
	return (0);
}
