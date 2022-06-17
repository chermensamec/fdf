#include "fdf.h"

void	get_width(char *file, s_struct *data)
{
	int fd;
	char *line;
	int	width;
	int	height;
	
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	data->width = word_count(line, ' ');
	height = 0;
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
		clock_t end = clock();
	}
	close(fd);
	data->height = height;
}