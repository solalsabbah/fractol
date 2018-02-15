/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:44:00 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/15 12:05:51 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WIDTH	1500
# define HEIGHT	1000

# define BLUE 	0x72CAFF
# define GREEN 	0x47D600
# define BROWN	0x752E00
# define WHITE 	0xFFFFFF
# define PINK 	0xFF65EF
# define YELLOW	0xFEF94D
# define PURPLE	0x3E0C76

# define ESC 53
# define DEL 51

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*image_ptr;
	int			*image;
	int			bpp;
	int			size_l;
	int			endian;
}				t_param;

int				ft_printf(char *format, ...);
int				ft_key(int keycode, t_param *p);

#endif
