#include "fdf.h"

int	index_elem(const char *s, int c)
{
	char	*str;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	str = (char *)s;
	while (i <= (int)len)
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}