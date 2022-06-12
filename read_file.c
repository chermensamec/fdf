#include "fdf.h"

int	ft_pow(int num, int pow)
{
	int	i;
	int	res;
	
	res = 1;
	i = 1;
	while (pow--)
		res *= num;
	return (res);
}

int	get_color(char	*color)
{
	int	i;
	int	ans;
	int	pow;
	int	num;

	pow = 1;
	ans = 0;
	i = ft_strlen(color + 2);
	while (color[i - 3])
	{
		if(color[i] >= '0' && color[i] <= '9')
			num = color[i] - '0';
		else if (color[i] >= 'A' && color[i] <= 'F')
			num = color[i] - 'A' + 10;
		else if (color[i] >= 'a' && color[i] <= 'f')
			num = color[i] - 'a' + 10;
		ans += num * ft_pow(16, pow);
		i--;
		pow++;
	}
	return (ans);
}

void filling_matrix(s_struct *data, char *file)
{
	int		fd;
	char	*line;
	char	**split_line;
	char	**split_line_dot;
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
			split_line_dot = ft_split(split_line[j], ',');
			data->matrix[i][j].h = ft_atoi(split_line_dot[0]);
			if (split_line_dot[1] == 0)
				data->matrix[i][j].c = 0xFFFFFF;
			else
				data->matrix[i][j].c = get_color(split_line_dot[1]);
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
	data->matrix = (dots **) malloc(sizeof(dots *) * data->height);
	while (i != data->height)
		data->matrix[i++] = (dots *)malloc(sizeof(dots) * data->width);
	
	filling_matrix(data, file);
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%8d ", data->matrix[i][j].c);
		}
		printf("\n");
	}
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%3d ", data->matrix[i][j].h);
		}
		printf("\n");
	}
}
