/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:05:51 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/26 15:29:53 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_mlx	mlx;

	if (argc != 2)
		return (1);
	data.map = NULL;
	data.x_offset = 0;
	data.y_offset = 0;
	data.x = 0;
	data.y = 0;
	data.row_size = 0;
	data.col_size = 0;
	data.bg = -1;
	data.pov = -1;
	data.sup = 0;
	data.mlx = &mlx;
	mlx.mlx_ptr = NULL;
	mlx.win_ptr = NULL;
	mlx.img_ptr = NULL;
	if (ft_map(&data, argv[1]) == NULL)
		return (1);
	if (ft_window(&data) == NULL)
		return (ft_freemap(&data), 1);
	return (ft_freemap(&data), 0);
}
