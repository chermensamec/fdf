#include "fdf.h"

int	get_width(char *file)
{
	int fd;
	char *line;
	char **split_line;
	int	i;

	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	while(split_line[i++] != 0)
		;
	close(fd);	
	return (i - 1);
}
int get_height(char *file)
{
	char *line;
	int	height;
	int	fd;

	fd = open(file, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while(line)
	{
		line = get_next_line(fd);
		height++;
		free(line);
	}
	return (height);
}