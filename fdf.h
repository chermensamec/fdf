#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) a > b ? a : b
#define ABS(a) a < 0 (-1 * a) : a

typedef struct {
	float	**matrix;
	int	height;
	int	width;
} s_struct;


// get next line 
#define BUFFER_SIZE 1
char	*get_line(int fd, char *buff, char *remainder);
char	*ft_get_remaind(char *remainder);
char	*ft_cut_line(char	*remainder);
char	*get_next_line(int fd);
int	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
// fdf
void read_file(s_struct *data, char *file);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *nptr);
#endif
