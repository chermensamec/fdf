#include "fdf.h"
#include <time.h>

int	get_y(char *map_name)
{
	char	*line;
	int		count_y;
	int	fd;

	count_y = 0;
	fd = open(map_name, O_RDONLY, 0);
	line = get_next_line(fd);
	printf("line %s\n", line);	
	while(line)
	{
		// clock_t begin = clock();
		free(line);
		line = get_next_line(fd);
		count_y++;
		// clock_t end = clock();
		// double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		//printf("width %f seconds\n", time_spent);	
	}
	close(fd);
	return (count_y);
}

int	main(int argc, char *argv[])
{
	s_struct *data;
	clock_t begin = clock();
	
	data = create_win();
	
	
	
	read_file(data, argv[1]);
	
	
	if (data->height > data->width)
		data->img_properties->zoom = 700 / data->height;
	else
		data->img_properties->zoom = 700 /  data->width;
	
	draw(data);


	mlx_put_image_to_window(data->window->mlx, data->window->mlx_win, data->window->img, 0, 0);
	mlx_key_hook(data->window->mlx_win, key_hook, data);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("all %f seconds\n", time_spent);	
	mlx_loop(data->window->mlx);
	return (0);	
}
