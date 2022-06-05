#include "fdf.h"

int	main(int argc, char *argv[])
{
	s_struct *data;
	data = create_win();
	read_file(data, argv[1]);
	mlx_pixel_put(data->mlx, data->mlx_win, 3, 4, 0xFFFFFF);
	brethenham(data, 4, 5, 500, 600);	
	//mlx_loop(data->mlx);
	return (0);	
}
