#include "fdf.h"

int	main(int argc, char *argv[])
{
	s_struct *data;
	data = create_win();
	read_file(data, argv[1]);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlx);
	return (0);	
}
