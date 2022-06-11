#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	// *x = *x * cos(0.8) - *y * sin(0.8);
	// *y = *x * sin(0.8) + *y * cos(0.8) - z;
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	brethenham(s_struct *data, float y, float x, float y1, float x1)
{
	float	step_x;
	float	step_y;
	float	max;
	int		z[2];
	int		color;

	color = data->matrix[(int) y][(int) x].c;
	z[0] = data->matrix[(int) y][(int) x].h;
	z[1] = data->matrix[(int) y1][(int) x1].h;

	x *= 20;
	y *= 20;
	x1 *= 20;
	y1 *= 20;


	x += data->window->win_width / 2;
	y += data->window->win_height / 1.5;
	x1 += data->window->win_width / 2;
	y1 += data->window->win_height / 1.5;

	
	isometric(&x, &y, z[0]);
	isometric(&x1, &y1, z[1]);

	step_x = (x1 - x);
	step_y = (y1 - y);

	max = get_max(get_abs(step_x), get_abs(step_y));
	
	step_x /= max;
	step_y /= max;
	while((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data, x, y, color);
		x += step_x;
		y += step_y;
	}
}