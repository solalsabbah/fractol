#include "fractol.h"

void	set_files(t_param *p)
{
	mlx_string_put(p->mlx, p->win, WIDTH / 2, 10, PINK, "Fileeee");
}

void	put_xpm(t_param *p)
{
	int	width;
	int	height;
	
	p->school_xpm = mlx_xpm_file_to_image(p->mlx, "xpm/42.xpm", &width, &height);
	mlx_put_image_to_window(p->mlx, p->win, p->school_xpm, 10, 10);
	p->zoom_xpm = mlx_xpm_file_to_image(p->mlx, "xpm/zoom.xpm", &width, &height);
	mlx_put_image_to_window(p->mlx, p->win, p->zoom_xpm, 10, 100);
	p->help_xpm = mlx_xpm_file_to_image(p->mlx, "xpm/help.xpm", &width, &height);
	mlx_put_image_to_window(p->mlx, p->win, p->help_xpm, 10, 200);
	p->color_xpm = mlx_xpm_file_to_image(p->mlx, "xpm/color.xpm", &width, &height);
	mlx_put_image_to_window(p->mlx, p->win, p->color_xpm, 10, 300);
	set_files(p);
}

void	draw_menu(t_param *p)
{
	int x;
	int y;
	
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (x < 50 || (y > 45 && y < 50))
				p->menu_data[x + y * WIDTH] = BLACK + y - x;
		}
	}
	mlx_put_image_to_window(p->mlx, p->win, p->menu_ptr, 0, 0);
	put_xpm(p);
}

void	set_menu(t_param *p)
{
	int	bpp; 
	int	size_l;
	int	endian;

	p->menu_ptr = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->menu_data = (int *)mlx_get_data_addr(p->menu_ptr, &bpp, &size_l, &endian);
	draw_menu(p);
}
