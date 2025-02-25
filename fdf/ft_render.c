#include "fdf.h"

void	ft_background(t_data *data)
{
	int	*background;
	int	i;
	int	color;

	background = (int *)(data->mlx->data_addr);
	color = BG_COLOR;
	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		if ((i % ((WIN_HEIGHT * WIN_WIDTH)/50) == 0) && data->bg % 2 == 1)
		{
			color += 0x020101;
		}
		background[i] = color;
		i++;
	}
}

void	ft_render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->bg == -1)
		ft_startinit(data);
	ft_background(data);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != NULL)
		{
			if (data->map[i][j]->x > 0)
				ft_drawlines(data, j, i, data->map[i][j], 1);
			if (data->map[i][j]->y > 0)
				ft_drawlines(data, j, i, data->map[i][j], 2);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->mlx->img_ptr, 0, 0);
}
