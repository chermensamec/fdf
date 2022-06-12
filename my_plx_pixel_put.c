#include "fdf.h"

void	my_mlx_pixel_put(s_struct *data, int x, int y, int color)
{
	char	*dst;
	// if (x > data->window->win_width)
	// 	x = data->window->win_width;
	// if (y > data->window->win_height)
	// 	y = data->window->win_height;
	dst = data->window->addr + (y * data->window->line_length + x * (data->window->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

