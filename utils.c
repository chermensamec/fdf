#include "fdf.h"

int	get_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int get_max(float x, int y)
{
	if (x > y)
		return (x);
	return (y);
}