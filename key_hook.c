#include "fdf.h"

int	key_hook(int keycode, s_struct *data)
{
	if (keycode == 27)
	{
		data->img_properties->height -= 10;
	
	}
	else if (keycode == 24)
	{
		data->img_properties->height += 10;
	
	}
	else if (keycode == 125)
	{
		data->img_properties->y_shift -= 50;
	}
	else if (keycode == 126)
	{
		data->img_properties->y_shift += 50;
	}
	else if (keycode == 123)
	{
		data->img_properties->x_shift -= 50;
	}
	else if (keycode == 124)
	{
		data->img_properties->x_shift += 50;
	}
	//mlx_destroy_image(data->window->mlx,data->window->img);
	mlx_destroy_image(data->window->mlx, data->window->img);
	data->window->img = mlx_new_image(data->window->mlx, data->window->win_height, data->window->win_width);
	data->window->addr = mlx_get_data_addr(data->window->img, &data->window->bits_per_pixel, &data->window->line_length,
								&data->window->endian);
	mlx_clear_window(data->window->mlx, data->window->mlx_win);
	draw(data);
	mlx_put_image_to_window(data->window->mlx, data->window->mlx_win, data->window->img, 0, 0);

	printf("%d\n", keycode);
	return(0);
}