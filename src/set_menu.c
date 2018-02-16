#include "fractol.h"

void	put_xpm(t_param *p)
{
	int	width;
	int	height;
	
	p->school_xpm = mlx_xpm_file_to_image(p->mlx, "xpm/42.xpm", &width, &height);
	mlx_put_image_to_window(p->mlx, p->win, p->school_xpm, 10, 10);
	
	p->zoom_xpm = mlx_xpm_file_to_image(p->mlx, "xpm/zoom.xpm", &width, &height);
	mlx_put_image_to_window(p->mlx, p->win, p->zoom_xpm, 10, 50);

	p->help_xpm = mlx_xpm_file_to_image(p->mlx, "xpm/help.xpm", &width, &height);
	mlx_put_image_to_window(p->mlx, p->win, p->help_xpm, 10, 95);
	
}

void	draw_menu(t_param *p)
{
	int x;
	int y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x < 50 || (y > 45 && y < 50))
				p->menu_data[x + y * WIDTH] = BLACK;
			x++;
		}
		y++;
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
