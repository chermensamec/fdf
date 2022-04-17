#include "fdf.h"

t_win *create_win(void)
{
	t_win	*img;

	img = malloc(sizeof(t_win));
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, 1920, 1080, "Hello world!");
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	return (img);
}
