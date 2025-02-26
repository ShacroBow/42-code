/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_utils1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:06:24 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/26 15:29:38 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_rotate_zx(t_data *data, t_point *point)
{
	double	original_z;

	original_z = point->z;
	point->z = original_z * cos(data->z_x_coef) + \
				point->x * -sin(data->z_x_coef);
	point->x = original_z * sin(data->z_x_coef) + \
				point->x * cos(data->z_x_coef);
}

void	ft_rotate_yz(t_data *data, t_point *point)
{
	double	original_y;

	original_y = point->y;
	point->y = original_y * cos(data->y_z_coef) + \
				point->z * sin(data->y_z_coef);
	point->z = original_y * -sin(data->y_z_coef) + \
				point->z * cos(data->y_z_coef);
}

void	ft_rotate_xy(t_data *data, t_point *point)
{
	double	original_x;

	original_x = point->x;
	point->x = original_x * cos(data->x_y_coef) + \
				point->y * -sin(data->x_y_coef);
	point->y = original_x * sin(data->x_y_coef) + \
				point->y * cos(data->x_y_coef);
}

void	ft_applypoint(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

void	ft_project_orthographic(t_data *data, t_point *point)
{
	point->x = (point->x - data->anchor_x) * data->distance;
	point->y = (point->y - data->anchor_y) * data->distance;
	point->z = 0;
}
