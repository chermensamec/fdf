#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include <time.h>
#include <time.h>



typedef struct
{
	int		h;
	int		c;
}	dots;

typedef struct 
{
	int		win_height;
	int		win_width;
	int 	line_length;
	void	*mlx;
	char	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
} s_win;

typedef struct{
	int	zoom;
	int	height;
	int x_shift;
	int	y_shift;
	float	alpha;
} s_img_settings;

typedef struct {
	dots	**matrix;
	int		height;
	int		width;
	s_win	*window;	
	s_img_settings	*img_properties;	
} s_struct;


// get next line 
#define BUFFER_SIZE 42
char	*get_next_line(int fd);
int	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
// fdf
int	key_hook(int keycode, s_struct *vars);
void		read_file(s_struct *data, char *file);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *nptr);
void		brethenham(s_struct *data, float x, float y, float x1, float y1);
s_struct	*create_win(void);
void		my_mlx_pixel_put(s_struct *data, int x, int y, int color);
void		draw(s_struct *data);
void		get_width(char *file, s_struct  *data);
int 		get_max(float x, int y);
int			get_abs(float x);
int			mouse(s_struct *win_ptr, int x, int y);
int	word_count(char	*str, char delimetr);
int	index_elem(const char *s, int c);
#endif
