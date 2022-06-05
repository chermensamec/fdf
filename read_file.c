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

void filling_matrix(s_struct *data, char *file)
{
	int		fd;
	char	*line;
	char	**split_line;
	int 	i;
	int		j;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		split_line = ft_split(line, ' ');
		j = 0;
		while (split_line[j])
		{
			data->matrix[i][j] = ft_atoi(split_line[j]);
			j++;
		}
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}
void read_file(s_struct *data, char *file)
{
	int i;

	i = 0;
	data->width = get_width(file);
	data->height = get_height(file);	
	data->matrix = (int **) malloc(sizeof(int *) * data->height);

	while (i != data->height)
		data->matrix[i++] = (int *)malloc(sizeof(int) * data->width); 
	filling_matrix(data, file);
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%3d ", data->matrix[i][j]);
		}
		printf("\n");
	}	
}
