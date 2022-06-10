#include "fdf.h"

void	brethenham(s_struct *data, float x, float y, float x1, float y1)
{
	float	step_x;
	float	step_y;
	float	max;

	step_x = (x1 - x);
	step_y = (y1 - y);

	max = get_max(get_abs(step_x), get_abs(step_y));
	
	step_x /= max;
	step_y /= max;
	printf("%f %f", step_x, step_y);
	while((int)(x - x1) || (int)(y - y1))
	{
		printf("%f, %f", x, y);
		x += step_x;
		y += step_y;
	}
}