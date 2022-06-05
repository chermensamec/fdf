#include "fdf.h"

s_struct *create_win(void)
{
	s_struct	*data;

	data = malloc(sizeof(s_struct));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "Hello world!");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	return (data);
}
