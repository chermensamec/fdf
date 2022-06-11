#include "fdf.h"

void	draw(s_struct *data)
{
	int	x;
	int	y;

	y = 0;
	while (y != data->height)
	{
		x = 0;
		while (x != data->width)
		{
			if (x != data->width - 1)
				brethenham(data, y, x, y, x + 1);
			if (y != data->height - 1)
				brethenham(data, y + 1, x, y, x);
			x++;
		}
		y++;
	}
}