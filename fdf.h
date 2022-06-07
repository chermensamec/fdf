#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>

typedef struct
{
	int	h;
	int	c;
}	dots;


typedef struct {
	dots	**matrix;
	int		height;
	int		width;
	int 	line_length; 	
	void	*mlx;
	char	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
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
void	read_file(s_struct *data, char *file);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
void	brethenham(s_struct *data, float x1, float y1, float x2, float y2);
s_struct	*create_win(void);
void	my_mlx_pixel_put(s_struct *data, float x, float y, int color);
void draw(s_struct *data);
#endif
