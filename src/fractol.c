/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:42:10 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/15 19:37:55 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_set(int c_re, int c_im)
{
	int z_re;
	int z_im;

	int n;

	z_re = c_re;
	z_im = c_im;
	
	n = 0;
	while (n < 50)
	{
		if (pow(z_re, 2) + pow(z_im, 2) > 4)
			return (0);
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re * z_re - (z_im * z_im) + c_re;
		n++;
	}
	return (1);
}

int	mandelbrot(t_param *p)
{
	float minRe;
	float maxRe;
	float minIm;
	float maxIm;
	
	float c_re;
	float c_im;
	
	float k_re;
	float k_im;

	int y;
	int x;
	minRe = -2;
	maxRe = 1;
	minIm = -1.2;
	maxIm = minIm + (maxRe - minRe) * HEIGHT / WIDTH;
	
	k_re = (maxRe - minRe) / (WIDTH  - 1);
	k_im = (maxIm - minIm) / (HEIGHT - 1);

	y = 1;
	while (y < HEIGHT)
	{
		c_im = maxIm - y * k_im;
		printf("%f\n", c_im );
		printf("%f\n", k_im );
		x = 1;
		while (x < WIDTH)
		{
			c_re = minRe + x * k_re;
			if (mandelbrot_set(c_re, c_im) == 1)
				p->image[x + y * WIDTH] = WHITE;
			x++;
		}
		y++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_param p;
	if (ac != 0)
		printf("%s\n", av[1]);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, "fractol");
	p.image_ptr = mlx_new_image(p.mlx, WIDTH, HEIGHT);
	p.image = (int *)mlx_get_data_addr(p.image_ptr,&p.bpp, &p.size_l, &p.endian);
	printf("%d\n", p.image[0]);
	mandelbrot(&p);
	mlx_put_image_to_window(p.mlx, p.win, p.image_ptr, 0, 0);
	mlx_hook(p.win, 2, 3, ft_key, &p);
	mlx_loop(p.mlx);
	return (0);
}
