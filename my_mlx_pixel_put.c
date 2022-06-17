#include "fdf.h"

void	my_mlx_pixel_put(s_struct *data, int x, int y, int color)
{
	char	*dst;
	if(data->img_properties->color == 0)
		color = 0xFFFFFF;
	dst = data->window->addr + (y * data->window->line_length + x * (data->window->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

