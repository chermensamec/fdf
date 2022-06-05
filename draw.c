#include "fdf.h"

int get_max(a, b)
{
	return (a > b ? a : b);
}

int get_abs(a)
{
	return (a < 0 ? (-1 * a) : a);
}

void	brethenham(s_struct *data, float x1, float y1, float x2, float y2)
{
	float	x_step;
	float	y_step;
	float	max;

	printf("%f %f %f %f\n", x1, y1, x2, y2);
	x1 *= 20;
	y1 *= 20;
	x2 *= 20;
	y2 *= 20;
	printf("%f %f %f %f\n", x1, y1, x2, y2);
	x_step = x1 - x2;
	y_step = y1 - y2;
	printf("%f %f\n", x_step, y_step);
	max = MAX(ABS(x_step), ABS(y_step));
	printf("max %f \n", max);
	printf("%f %f\n", x_step, y_step);
	x_step /= max;
	y_step /= max;
	printf("%f %f\n", x_step, y_step);
	mlx_pixel_put(data->mlx, data->mlx_win, 100, 100, 0xFFFFFF);
	// while ((int)(x1 - x2) || (int)(y1 - y2))
	// {
	// 	printf("%f %f \n", x1, y1);
	// 	mlx_pixel_put(data->mlx, data->mlx_win, x1, y1, 0xFFFFFF);
	// 	x1 += x_step;
	// 	y1 += y_step;
	// }
}
