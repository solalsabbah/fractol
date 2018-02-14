/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:42:10 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/14 17:24:05 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_param p;
	if (ac != 0)
		printf("%s\n", av[1]);

	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, "fractol");
//	mlx_hook(p.win, 2, 3, ft_key, &p);
	mlx_loop(p.mlx);
	return (0);
}
