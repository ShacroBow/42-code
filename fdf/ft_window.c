#include "fdf.h"

int	destroy_handler(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

void	*destroy_win(t_mlx *mlx)
{
	if (!mlx)
		return (NULL);
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	return (NULL);
}

static int	set_img_props(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img_ptr)
	{
		destroy_win(mlx);
		return (-1);
	}
	mlx->data_addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel, \
			&mlx->size_line, &mlx->endian);
	if (!mlx->data_addr)
	{
		destroy_win(mlx);
		return (-1);
	}
	return (0);
}

static int	set_win_props(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		destroy_win(mlx);
		return (-1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
								WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!mlx->win_ptr)
	{
		destroy_win(mlx);
		return (-1);
	}
	return (0);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy_handler(data->mlx);
	if (keycode == KEY_SPACE)
		printf("cozx[%f]coyz[%f]coxy[%f]", data->z_x_coef, data->y_z_coef, data->x_y_coef);
	if (keycode == KEY_LEFT)
		data->x_y_coef += 0.1;
	else if (keycode == KEY_RIGHT)
		data->x_y_coef -= 0.1;
	else if (keycode == KEY_UP)
		data->y_z_coef += 0.1;
	else if (keycode == KEY_DOWN)
		data->y_z_coef -= 0.1;
	else if (keycode == KEY_PG_DOWN)
		data->z_x_coef -= 0.1;
	else if (keycode == KEY_PG_UP)
		data->z_x_coef += 0.1;
	else if (keycode == KEY_PLUS)
		data->zoom += 0.2;
	else if (keycode == KEY_MINUS)
		data->zoom -= 0.2;
	draw_background(data);
	render_map(data);
	return (0);
}

void	*ft_window(t_data *data)
{
	t_mlx	*mlx;

	mlx = data->mlx;
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img_ptr = NULL;
	if (set_win_props(data->mlx) == -1)
		return (NULL);
	if (set_img_props(data->mlx) == -1)
		return (NULL);
	mlx_hook(mlx->win_ptr, DestroyNotify, 0, destroy_handler, mlx);
	mlx_key_hook(mlx->win_ptr, key_handler, data);
	ft_render(data);
	mlx_loop(mlx->mlx_ptr);
	destroy_win(mlx);
	return (data);
}
