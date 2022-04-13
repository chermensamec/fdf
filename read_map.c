#include "fdf.h"

void	add_line(char ***arr, int size)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		new[i] = (*arr)[i];
		i++;
	}
	if (size != 0)
		free(*arr);
	*arr = new;
}

int  read_map(char *file)
{
	int		fd;
	char	*line;
	char	**res;
	int 	size;
	int		i;

	size = 0;
	if (ft_strcmp(file + ft_strlen(file) - 4, ".fdf"))
		return (0);
	fd = open(file, O_RDONLY, 0644);
	line = get_next_line(fd);
	while (line)
	{
		add_line(&res, size);
		res[size++] = line;
		line = get_next_line(fd);
	}
	printf("%d\n", size);
	i = 0;
	while (i < size)
	{
		printf("%s", res[i]);
		free(res[i++]);
	}
	free(res);
	close(fd);
	return (0);
}
