#include "fdf.h"

int	close_win(int keycode, t_win *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	return (0);
}

int	main(void)
{
	t_win	*img;
	img = creat_win();
	my_mlx_pixel_put (img, 4, 4, 0x00ff0000);	
	//mlx_hook(img->mlx_win, 2, 1L<<0, close_win, img);
	//draw_rectangle(img, 100, 100, 0);
	//draw_texture(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_loop(img->mlx);
}
