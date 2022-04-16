#ifndef FDF_H
# define FDF_H
#define  BUFFER_SIZE 10
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <mlx.h>
typedef struct	s_win {
	void	*mlx;
	char	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_win;

int 	read_map(char *file);
int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
void	draw_rectangle(t_win *win, int height, int width, int empty);
t_win	*creat_win(void);
void	draw_texture(t_win *win);
#endif
