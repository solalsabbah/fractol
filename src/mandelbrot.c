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

double interpolate(double start, double end, double zoom)
{
	return (start + (end - start) * zoom);
}

int	mandelbrot(t_param *p)
{
	double c_re;
	double c_im;

	double k_re;
	double k_im;

	double mouseRe;
	double mouseIm;

//	double posx; // recentrer limage
//	double posy; // recentrer limage
	int y;
	int x;
	int n;

	if (p->init == 0)
	{
		p->minRe = -2.1;
		p->maxRe = 0.6;
		p->minIm = -1.2;
		p->maxIm = p->minIm + ((p->maxRe - p->minRe) * HEIGHT - 1) / (WIDTH - 1);
		p->init = 1;
	}
	mouseRe = p->minRe + p->zoomi / (WIDTH / (p->maxRe - p->minRe));
	mouseIm = p->minIm + p->zoomj / (HEIGHT / (p->maxIm - p->minIm));


//	posx = (mouseRe - p->minRe < p->maxRe - mouseRe) ? -0.1 : 0.1;	
//	posy = (mouseIm - p->minIm < p->maxIm - mouseIm) ? -0.1 : 0.1;	

	printf("\nici : %f\n", mouseRe);
	printf("ici : %f\n", mouseIm);

/*	p->minRe -= p->zoomx;
	p->maxRe += p->zoomx;
	p->minIm -= p->zoomy;
	p->maxIm += p->zoomy;
*/
	p->minRe = interpolate(mouseRe, p->minRe, 1 / p->zoomx); 
	p->maxRe = interpolate(mouseRe, p->maxRe, 1 / p->zoomx);
	p->minIm = interpolate(mouseIm, p->minIm, 1 / p->zoomx);
	p->maxIm = interpolate(mouseIm, p->maxIm, 1 / p->zoomx);

	
	printf("\nici : %f\n", p->minRe);
	printf("ici : %f\n", p->minIm);

	k_re = (p->maxRe - p->minRe) / WIDTH;
	k_im = (p->maxIm - p->minIm) / HEIGHT;
	y = 0;
	while (++y < HEIGHT)
	{
		c_im = p->maxIm - y * k_im;
		x = 0;
		while (++x < WIDTH)
		{
			c_re = p->minRe + x * k_re;
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
