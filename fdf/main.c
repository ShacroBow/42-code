#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_mlx	mlx;

	data.map = NULL;
	data.x = 0;
	data.y = 0;
	data.row_size = 0;
	data.col_size = 0;
	data.mlx = &mlx;
	mlx.mlx_ptr = NULL;
	mlx.win_ptr = NULL;
	mlx.img_ptr = NULL;
	if (argc != 2)
		return (1);
	if (ft_map(&data, argv[1]) == NULL)
		return (1);
	if (ft_window(&data) == NULL)
	{
		ft_freemap(&data);
		return (1);
	}
	ft_freemap(&data);
}
