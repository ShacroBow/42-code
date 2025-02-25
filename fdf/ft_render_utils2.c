#include "fdf.h"

void	ft_transform_point(t_data *data, t_point *point)
{
	if (data->pov == -1)
	{
		point->x = (point->x - data->anchor_x) * data->distance;
		point->y = (point->y - data->anchor_y) * data->distance;
		point->z = point->z * data->height;
		ft_rotate_xy(data, point);
		ft_rotate_yz(data, point);
		ft_rotate_zx(data, point);
	}
	else if (data->pov == 1)
	{
		ft_project_orthographic(data, point);
		ft_rotate_xy(data, point);
	}
	point->x += data->x + data->x_offset;
	point->y -= data->y + data->y_offset;
	point->x *= data->zoom;
	point->y *= data->zoom;
	point->z *= data->zoom;
}

void ft_renderpixel(t_data *data, int x, int y, int color)
{
	int i;
	int adjusted_x;
	int adjusted_y;
	int within_x_bounds;
	int within_y_bounds;

	adjusted_x = (WIN_WIDTH / 2) + x;
	adjusted_y = (WIN_HEIGHT / 2) + y;
	within_x_bounds = (adjusted_x >= 0) && (adjusted_x < WIN_WIDTH);
	within_y_bounds = (adjusted_y >= 0) && (adjusted_y < WIN_HEIGHT);
	if (within_x_bounds && within_y_bounds)
	{
		i = (adjusted_x * data->mlx->bits_per_pixel / 8) + \
			(adjusted_y * data->mlx->size_line);
		data->mlx->data_addr[i] = color;
		data->mlx->data_addr[i + 1] = color >> 8;
		data->mlx->data_addr[i + 2] = color >> 16;
	}
}

void ft_linerender(t_data *data, t_point p1, t_point p2, int color, int s)
{
	int i;
	double stepx;
	double stepy;

	i = 0;
	stepx = p1.x;
	stepy = p1.y;
	while (i < s)
	{
		ft_renderpixel(data, (int)stepx, (int)stepy, color);
		stepx += (p2.x - p1.x) / (double)s;
		stepy += (p2.y - p1.y) / (double)s;
		i++;
	}
}

void	ft_line(t_data *data, t_point p1, t_point p2, int color)
{
	double x0;
	double y0;
	double dx;
	double dy;
	int steps;

	x0 = p1.x;
	y0 = p1.y;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	ft_linerender(data, p1, p2, color,steps);
}

void	ft_drawlines(t_data *data, int x, int y, t_point *point, int state)
{
	t_point	tmptarget;
	t_point	tmppoint;
	int ym;
	int xm;

	ym = 0;
	xm = 0;
	ft_applypoint(&tmppoint, x, y, point->z);
	ft_transform_point(data, &tmppoint);
	if (state == 1)
		xm = 1;
	else if (state == 2)
		ym = 1;
	ft_applypoint(&tmptarget, x - xm, y - ym, data->map[y - ym][x - xm]->z);
	ft_transform_point(data, &tmptarget);
	ft_line(data, tmppoint, tmptarget, data->map[y - ym][x - xm]->color);
}
