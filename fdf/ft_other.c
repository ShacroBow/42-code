#include "fdf.h"

void	ft_keyhandler_transform(int keycode, t_data *data)
{
	if (keycode == KEY_A)
		data->x_offset += 20;
	else if (keycode == KEY_D)
		data->x_offset -= 20;
	else if (keycode == KEY_W)
		data->y_offset -= 20;
	else if (keycode == KEY_S)
		data->y_offset += 20;
}

int	ft_keyhandler(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_destroyhandler(data->mlx);
	if (keycode == KEY_SPACE)
		ft_startinit(data);
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
	else if (keycode == KEY_P)
		data->pov *= -1;
	ft_keyhandler_transform(keycode, data);
	ft_render(data);
	return (0);
}

void	ft_startinit(t_data *data)
{
	int	width_distance;
	int	height_distance;

	width_distance = (PADDED_WIDTH) / (data->row_size);
	height_distance = (PADDED_HEIGHT) / (data->col_size);
	if (width_distance > height_distance)
		data->distance = height_distance;
	else
		data->distance = width_distance;
	data->bg += 1;
	data->x = 0;
	data->y = 0;
	data->zoom = 0.7;
	data->height = 5;
	data->x_y_coef = -0.6;
	data->y_z_coef = -1;
	data->z_x_coef = 0;
}
