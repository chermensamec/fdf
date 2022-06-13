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

	ans = 0;

	i = ft_strlen(color + 3);
	pow = 0;
	while (color[i])
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
	int 	i;
	int		j;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	clock_t begin = clock();
	while (line)
	{
		split_line = ft_split(line, ' ');
		j = 0;
		while (split_line[j])
		{
			data->matrix[i][j].h = ft_atoi(split_line[j]);
			// data->matrix[i][j].c = 0xFFFFFF;
			if ( index_elem(split_line[j],',') != 0)
				data->matrix[i][j].c = get_color(split_line[j] + index_elem(split_line[j],','));
			j++;
		}
		i++;
		line = get_next_line(fd);
	}
	clock_t end = clock();
	printf("get matrix %f", (double)(end - begin) / CLOCKS_PER_SEC);
	close(fd);
}
void read_file(s_struct *data, char *file)
{
	int i;

	i = 0;
	get_width(file, data);
	data->matrix = (dots **) malloc(sizeof(dots *) * data->height);
	while (i != data->height)
		data->matrix[i++] = (dots *)malloc(sizeof(dots) * data->width);
	if (data->height > data->width)
		data->img_properties->zoom = 700 / data->height;
	else
		data->img_properties->zoom = 700 /  data->width;
	filling_matrix(data, file);
}
