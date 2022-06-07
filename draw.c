#include "fdf.h"

int get_max(a, b)
{
	return (a > b ? a : b);
}

int get_abs(a)
{
	return (a < 0 ? (-a) : a);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void draw(s_struct *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (j != data->width - 1)
				brethenham(data, j, i, j + 1, i);
			if (i != data->height - 1)
				brethenham(data, j, i, j, i + 1);
			j++;
			break;
		}
		i++;
		break;
	}
}

void	brethenham(s_struct *data, float x1, float y1, float x2, float y2)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z1, z2;
	int		color;

	z1 = data->matrix[(int) y1][(int) x1].h;
	z2 = data->matrix[(int) y2][(int) x2].h;
	color = data->matrix[(int) y1][(int ) x1].c;

	x1 = x1 * 20;
	y1 = y1 * 20;
	x2 = x2 * 20;
	y2 = y2 * 20;
	
	//printf("x1 %f y1 %f x2 %f y2 %f \n", x1, y1, x2, y2);
	// isometric(&x1, &y1, z1);
	// isometric(&x2, &y2, z2);

	x_step = x2 - x1;
	y_step = y2 - y1;
	max = get_max(get_abs(x_step), get_abs(y_step));
	//printf("max %f x_step %f y_step %f\n", max, x_step, y_step);
	x_step /= max;
	y_step /= max;
	printf("start x_step %f y_step %f x1 %f y1 %f x2 %f y2 %f \n", x_step, y_step, x1, y1, x2, y2);
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		printf("x_step %f y_step %f x1 %f y1 %f x2 %f y2 %f \n", x_step, y_step, x1, y1, x2, y2);
		my_mlx_pixel_put(data, x1, y1, color);
		x1 += x_step;
		y1 += y_step;
		break;
	}
}
