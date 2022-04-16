#include "fdf.h"

int	create_trgb()
{
	int	x[4];
	int	i;

	i = 0;
	while (i != 4)
		x[i++] = rand() % 256;
	return (x[0] << 24 | x[1] << 16 | x[2] << 8 | x[3]);
}

void	draw_texture(t_win *win)
{
	int	y;
	int x;

	y = 0;
	while (y != 1080)
	{
		x = 0;
		while (x != 1920)
		{
			my_mlx_pixel_put(win, x, y, create_trgb());
			x++;
		}
		y++;
	}
}
