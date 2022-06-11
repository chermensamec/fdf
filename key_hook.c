#include "fdf.h"

int	key_hook(int keycode, s_struct *vars)
{
	printf("%d\n", keycode);
	return(0);
}