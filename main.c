#include "fdf.h"
#include <time.h>

int	main(int argc, char *argv[])
{
	s_struct *data;
	clock_t	seconds;
	seconds = clock();
	data = create_win();
	// printf("create %ld\n", seconds);
	seconds = clock();
	read_file(data, argv[1]);
	// printf("read_file %ld\n", seconds );
	seconds = clock();
	draw(data);
	// printf("draw %ld\n", seconds);
	seconds = clock();
	mlx_put_image_to_window(data->window->mlx, data->window->mlx_win, data->window->img, 0, 0);
	// printf("mlx_put_image_to_window %ld", seconds );
	mlx_key_hook(data->window->mlx_win, key_hook, data);
	mlx_loop(data->window->mlx);
	return (0);	
}
