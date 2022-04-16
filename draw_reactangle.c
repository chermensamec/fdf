#include "fdf.h"

void	draw_rectangle(t_win *win, int height, int width, int empty)
{
	int	y;
	int x;

	if (!empty)
	{
		y = 0;
		while (y != height)
		{
			x = 0;
			while (x != width)
			{
				my_mlx_pixel_put(win, x, y, 0x6fff0000);
				x++;	
			}
			y++;
		}
	}
	else 
	{
		x = 0;
		while (x != width)
		{
			my_mlx_pixel_put(win, x, 0, 0xff0000);	
			my_mlx_pixel_put(win, x, height - 1, 0xff0000);
			x++;	
		}
		y = 0;
		while (y != height)
		{
			my_mlx_pixel_put(win, 0, y, 0xff0000);	
			my_mlx_pixel_put(win, width - 1, y, 0xff0000);
			y++;
		}
	}
}
