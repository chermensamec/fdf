#include "fdf.h"

void	destroy_win(s_struct *data)
{
	int	i;

	i = 0;
	free(data->window->addr);
	free(data->window->img);
	mlx_destroy_window(data->window->mlx, data->window->mlx_win);
	free(data->img_properties);
	while(i < data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
	free(data->window->mlx);
	free(data->window);
	free(data);
	exit(0);
}