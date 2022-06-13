#include "fdf.h"

int	word_count(char	*str, char delimetr)
{
	int	i;
	int	count;
	int	f;

	f = 1;
	i = 0;
	count = 0;

	while (str[i])
	{
		if (f == 1 && str[i] != delimetr)
		{
			count++;
			f = 0;
		}
		else if (f == 0 && str[i] == delimetr)
		{
			f = 1;
		}
		i++;
	}
	return (count);
}