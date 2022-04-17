#include "fdf.h"

int	close_win(int keycode, t_win *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	return (0);
}

int	key_hook(int keycode, t_win *vars)
{
	printf("Hello from key_hook %d!\n ", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_win *vars)
{
	printf("Hello from mouse_hook %d !\n", keycode);
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	printf("Move to x = %d y = %d\n", x, y);
}
int mouse_down(int button, int x, int y, t_mouse *param)
{
	param->xcur = x;
	param->ycur = y;	
	printf("Down x = %d y = %d\n", x, y);
}
int mouse_up(int button, int x, int y, t_mouse *param)
{
	param->xcur = x;
	param->ycur = y;	
	printf("UP x = %d y = %d\n", x, y);

}
int	main(void)
{
	t_win	*img;
	t_mouse	mouse;
	img = create_win();
	//mlx_hook(img->mlx_win, 6, 0, mouse_move, &img);
	mlx_hook(img->mlx_win, 4, 0, mouse_down, &mouse);
	mlx_hook(img->mlx_win, 5, 0, mouse_down, &mouse);
	mlx_key_hook(img->mlx_win, key_hook, &img);
	//mlx_mouse_hook(img->mlx_win, mouse_hook, &img);
	draw_texture(img);	
	draw_rectangle(img, 100, 100, 0);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_loop(img->mlx);
}
