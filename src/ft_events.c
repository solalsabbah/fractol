/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:01:35 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/15 18:48:56 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key(int keycode, t_param *p)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == DEL)
		mlx_clear_window(p->mlx, p->win);
	return (keycode);
}
