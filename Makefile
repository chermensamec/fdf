NAME = fdf

SRC = get_next_line.c get_next_line_utils.c main.c create_win.c\
	ft_strcmp.c read_map.c draw_reactangle.c my_mlx_pixel_put.c\
	draw_texture.c

OBJ = $(patsubst %.c, %.o, $(SRC))
GCC = gcc

FLAGS =# -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	make -C ./mlx
	$(GCC) $(FLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
fclean : clean
	rm $(NAME)	
