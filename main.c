#include "fdf.h"

int	main(int argc, char *argv[])
{
	s_struct *data;
	data = (s_struct *) malloc(sizeof(s_struct));
	read_file(data, argv[1]);
	return (0);	
}
