/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:44:00 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/14 15:50:53 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <math.h>
#include <mlx.h>

# define WIDTH 1500
# define HEIGHT 1000

typedef struct	s_param
{
	void *mlx;
	void *win;
}				t_param;

int	ft_printf(char *format, ...);

#endif
