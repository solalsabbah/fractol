/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:44:00 by ssabbah           #+#    #+#             */
/*   Updated: 2018/03/02 18:42:33 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WIDTH	2000
# define HEIGHT	1100

# define BLUE 	0x72CAFF
# define RED	0xB50000
# define GREEN 	0x47D600
# define BROWN	0x752E00
# define WHITE 	0xFFFFFF
# define BLACK	0x000000
# define PINK 	0xFF65EF
# define YELLOW	0xFEF94D
# define PURPLE	0x3E0C76

# define ESC 53
# define DEL 51

typedef struct	s_fract
{
}				t_fract;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*image_ptr;
	void		*menu_ptr;
	int			*image;
	int			*menu_data;
	int			bpp;
	int			size_l;
	int			endian;
	int			map;
	int			zoomi;
	int			zoomj;
	int			init;
	double		zoomx;
	double		zoomy;

	void		*logo_xpm;
	void		*zoom_xpm;
	void		*help_xpm;
	void		*color_xpm;
	void		*school_xpm;

	double		minRe;
	double		maxRe;
	double		minIm;
	double		maxIm;
}			t_param;

int				ft_printf(char *format, ...);
void 			launch_map(t_param *p);
int				ft_key(int keycode, t_param *p);
int				mouse_hook(int bouton, int x, int y, t_param *p);
int				mandelbrot(t_param *p);
int				julia(t_param *p);
void			set_menu(t_param *p);

#endif
