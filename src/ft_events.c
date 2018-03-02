/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:01:35 by ssabbah           #+#    #+#             */
/*   Updated: 2018/03/02 18:54:48 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int bouton, int x, int y, t_param *p)
{
	printf("%d %d\n", x, y);
	if (bouton == 1)
	{
		p->zoomi = x;
		p->zoomj = y;
		return (1);
	}
	if (bouton == 5)
		p->zoomx += 0.01;
	if (bouton == 4)
		p->zoomx -= 0.01;
	mlx_clear_window(p->mlx, p->win);
	launch_map(p);
	return (1);
}

int	ft_key(int keycode, t_param *p)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		exit(0);
	if (keycode == DEL)
		mlx_clear_window(p->mlx, p->win);
	return (keycode);
}
