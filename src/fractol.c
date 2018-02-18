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

int main(int ac, char **av)
{
	t_param p;
	if (ac != 0)
		printf("%s\n", av[1]);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, "Fractol by ssabbah");
	p.image_ptr = mlx_new_image(p.mlx, WIDTH, HEIGHT);
	p.image = (int *)mlx_get_data_addr(p.image_ptr,&p.bpp, &p.size_l, &p.endian);
	set_menu(&p);
	mandelbrot(&p);
//	mlx_put_image_to_window(p.mlx, p.win, p.menu_ptr, 0, 0);
	mlx_put_image_to_window(p.mlx, p.win, p.image_ptr, 50, 50);
	mlx_hook(p.win, 2, 3, ft_key, &p);
	mlx_loop(p.mlx);
	return (0);
}
