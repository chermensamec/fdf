#include "fdf.h"

s_struct *create_win(void)
{
	s_struct	*data;
	data = malloc(sizeof(s_struct));
	data->window = malloc(sizeof(s_win));
	data->img_properties = malloc(sizeof(s_img_settings));
	data->window->win_height = 1920;
	data->window->win_width = 1080;
	data->window->mlx = mlx_init();
	data->window->mlx_win = mlx_new_window(data->window->mlx, data->window->win_height, data->window->win_width, "Hello world!");
	data->window->img = mlx_new_image(data->window->mlx, data->window->win_height, data->window->win_width);
	data->window->addr = mlx_get_data_addr(data->window->img, &data->window->bits_per_pixel, &data->window->line_length,
								&data->window->endian);
	data->img_properties->zoom = 20;
	data->img_properties->height = 1; 
	data->img_properties->x_shift = 0;
	data->img_properties->y_shift = 0;
	data->img_properties->alpha = 0.8;
	return (data);
}
