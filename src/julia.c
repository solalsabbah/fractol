/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:42:20 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/26 18:35:06 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_set(double c_re, double c_im)
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
		if (pow(z_re, 2) + pow(z_im, 2) > 4)
			return (n);
		tmp = z_im;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re * z_re - (tmp * tmp) + c_re;
		n++;
	}
	return (-1);
}

int	julia(t_param *p)
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
	minRe = -10;
	maxRe = 10;
	minIm = -5;
	maxIm = minIm + ((maxRe - minRe) * HEIGHT) / WIDTH;

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
			if ((n = julia_set(c_re, c_im)) == -1)
				p->image[x + y * WIDTH] = WHITE;
			else if (n != 0)
				p->image[x + y * WIDTH] = BLACK + n * 10;
		}
	}
	return (0);
}
