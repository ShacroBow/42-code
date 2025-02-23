#include "fdf.h"

void	zoom(t_data *data, t_point *point)
{
	point->x *= data->zoom;
	point->y *= data->zoom;
	point->z *= data->zoom;
}

void	translate(t_data *data, t_point *point)
{
	point->x += data->x;
	point->y -= data->y;
}

void	rotate_z_x(t_data *data, t_point *point)
{
	double	original_z;

	original_z = point->z;
	point->z = original_z * cos(data->z_x_coef) \
		+ point->x * -sin(data->z_x_coef);
	point->x = original_z * sin(data->z_x_coef) \
		+ point->x * cos(data->z_x_coef);
}

void	rotate_y_z(t_data *data, t_point *point)
{
	double	original_y;

	original_y = point->y;
	point->y = point->z * sin(data->y_z_coef) \
		+ original_y * cos(data->y_z_coef);
	point->z = point->z * cos(data->y_z_coef) \
		+ original_y * -sin(data->y_z_coef);
}

void	rotate_x_y(t_data *data, t_point *point)
{
	double	original_x;

	original_x = point->x;
	point->x = original_x * cos(data->x_y_coef) \
		+ point->y * -sin(data->x_y_coef);
	point->y = original_x * sin(data->x_y_coef) \
		+ point->y * cos(data->x_y_coef);
}

void	set_camera_props(t_data *data)
{
	double	width_distance;
	double	height_distance;

	width_distance = (double)(PADDED_WIDTH) / (data->row_size);
	height_distance = (double)(PADDED_HEIGHT) / (data->col_size);
	if (width_distance > height_distance)
		data->distance = height_distance;
	else
		data->distance = width_distance;
	data->height = 5;
	data->zoom = 0.7;
	data->x_y_coef = -0.4;
	data->y_z_coef = -0.9;
	data->z_x_coef = 0;
	data->x = 0;
	data->y = 0;
}

void	set_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

void	render_point(t_data *data, t_point *point)
{
	point->x = (point->x - data->anchor_x) * data->distance;
	point->y = (point->y - data->anchor_y) * data->distance;
	point->z = point->z * data->height;
	rotate_x_y(data, point);
	rotate_y_z(data, point);
	rotate_z_x(data, point);
	translate(data, point);
	zoom(data, point);
}

static void	put_pixel(t_data *data, int x, int y, int color)
{
	int	i;

	if ((WIN_WIDTH / 2) + x >= 0 && abs((WIN_WIDTH / 2) + x) < WIN_WIDTH && \
	(WIN_HEIGHT / 2) + y >= 0 && abs((WIN_HEIGHT / 2)) + y < WIN_HEIGHT)
	{
		i = (((WIN_WIDTH / 2) + x) * data->mlx->bits_per_pixel / 8) + \
		(((WIN_HEIGHT / 2) + y) * data->mlx->size_line);
		data->mlx->data_addr[i] = color;
		data->mlx->data_addr[++i] = color >> 8;
		data->mlx->data_addr[++i] = color >> 16;
	}
}

static void	draw_line(t_data *data, t_point p1, t_point p2, unsigned long color)
{
	double	x0;
	double	y0;
	int		steps;
	int		i;

	x0 = p1.x;
	y0 = p1.y;
	steps = abs(p2.y - p1.y);
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		steps = abs(p2.x - p1.x);
	i = 0;
	while (i <= steps)
	{
		put_pixel(data, (int)x0, (int)y0, color);
		x0 += (p2.x - p1.x) / (double)steps;
		y0 += (p2.y - p1.y) / (double)steps;
		i++;
	}
}

static int	ft_bresenham_helper(t_point *p1, t_point *p2, int *sx, int *sy)
{
	int	x0;
	int	y0;
	int	dx;
	int	dy;
	int	err;

	x0 = p1->x;
	y0 = p1->y;
	dx = p2->x - x0;
	dy = p2->y - y0;
	if (dx > 0)
		*sx = 1;
	else
		*sx = -1;
	if (dy > 0)
		*sy = 1;
	else
		*sy = -1;
	dx = abs(dx);
	dy = abs(dy);
	err = dx - dy;
	return (err);
}

void	ft_bresenham_line(t_data *data, t_point p1, t_point p2, int color)
{
	int	x0;
	int	y0;
	int	sx;
	int	sy;
	int	err;

	x0 = p1.x;
	y0 = p1.y;
	err = ft_bresenham_helper(&p1, &p2, &sx, &sy);
	while (1)
	{
		put_pixel(data, x0, y0, color);
		if (x0 == p2.x && y0 == p2.y)
			break ;
		if ((err * 2) > -(abs(p2.y - y0)))
		{
			err -= (p2.y - y0);
			x0 += sx;
		}
		if ((err * 2) < abs(p2.x - x0))
		{
			err += abs(p2.x - x0);
			y0 += sy;
		}
	}
}

static void	set_lines(t_data *data, int x, int y, t_point *point)
{
	t_point	left_point;
	t_point	top_point;
	t_point	curr_point;

	set_point(&curr_point, x, y, point->z);
	render_point(data, &curr_point);
	if (x > 0)
	{
		set_point(&left_point, x - 1, y, data->map[y][x - 1]->z);
		render_point(data, &left_point);
		draw_line(data, curr_point, left_point, data->map[y][x - 1]->color);
	}
	if (y > 0)
	{
		set_point(&top_point, x, y - 1, data->map[y - 1][x]->z);
		render_point(data, &top_point);
		draw_line(data, curr_point, top_point, data->map[y - 1][x]->color);
	}
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != NULL)
		{
			set_lines(data, j, i, data->map[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->mlx->img_ptr, 0, 0);
}

void	draw_background(t_data *vars)
{
	int	*background;
	int	i;

	background = (int *)(vars->mlx->data_addr);
	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		background[i] = BG_COLOR;
		i++;
	}
}

void	ft_render(t_data *data)
{
	set_camera_props(data);
	draw_background(data);
	render_map(data);
}
