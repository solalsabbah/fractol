/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:42:10 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/27 17:37:45 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	launch_map(t_param *p)
{
	p->image_ptr = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->image = (int *)mlx_get_data_addr(p->image_ptr,&p->bpp, &p->size_l, &p->endian);
	if (p->map == 1)
		mandelbrot(p);
	if (p->map == 2)
		julia(p);
	set_menu(p);
	mlx_put_image_to_window(p->mlx, p->win, p->image_ptr, 50, 50);
}

int		choose_fractal(char *str, t_param *p)
{
	p->map = 0;
	if (ft_strcmp(str, "Mandelbrot") == 0)
		p->map = 1;
	if (ft_strcmp(str, "Julia") == 0)
		p->map = 2;
	return (0);
}

void	init(t_param *p)
{
	p->zoomx = 0;
}

int		main(int ac, char **av)
{
	t_param p;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, "Fractol by ssabbah");
	init(&p);
	if (ac == 2)
	{
		choose_fractal(av[1], &p);
		if (p.map == 0)
			return (0);
	}	
	else 
		printf("Please choose a fractal :\n-> Mandelbrot\n-> Julia\n");
	launch_map(&p);
//	mlx_put_image_to_window(p.mlx, p.win, p.menu_ptr, 0, 0);
	mlx_mouse_hook(p.win, mouse_hook, &p);
	mlx_hook(p.win, 2, 3, ft_key, &p);
	mlx_loop(p.mlx);
	return (0);
}
