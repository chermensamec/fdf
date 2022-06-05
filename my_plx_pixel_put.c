#include "fdf.h"

void	my_mlx_pixel_put(s_struct *data, float x, float y, int color)
{
	char	*dst;

	dst = data->addr + (int)(y * data->width + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

