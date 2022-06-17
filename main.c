#include "fdf.h"
#include <time.h>

int	main(int argc, char *argv[])
{
	s_struct *data;

	data = create_win();
	read_file(data, argv[1]);
	if (data->height > data->width)
		data->img_properties->zoom = 700 / data->height;
	else
		data->img_properties->zoom = 700 /  data->width;
	draw(data);
	mlx_put_image_to_window(data->window->mlx, data->window->mlx_win, data->window->img, 0, 0);
	mlx_key_hook(data->window->mlx_win, key_hook, data);
	mlx_loop(data->window->mlx);
	return (0);	
}
