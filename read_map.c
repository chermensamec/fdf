#include "fdf.h"

char	**add_line(char ***arr, int size)
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
	*arr = new;
	return (new);

}

int  read_map(char *file)
{
	int		fd;
	char	*line;
	char	**res;
	int		i;

	i = -1;
	/*if (ft_strcmp(file + ft_strlen(file) - 4, ".fdf"))
		return (0);	*/
	fd = open(file, O_RDONLY, 0644);
	line = get_next_line(fd);
	printf("%s\n", line);
	while (line)
	{
		add_line(&res, ++i);
		res[i] = line;
		line = get_next_line(fd);
	}
	while (i > 0)
		printf("%s", res[i--]);
	return (0);
}
