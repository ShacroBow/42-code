/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:06:03 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/26 15:28:43 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "libft/libft.h"
# include <mlx.h>
# include <X11/Xutil.h>

# include <stdio.h>
# define BUFFER_SIZE 1000
# define BG_COLOR 0x09090B
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define DEF_LINECOLOR 0xffffff
# define WIN_TITLE "Khaled's FdF"
# define PADDED_WIDTH 1920
# define PADDED_HEIGHT 1080
# define KEY_ESC XK_Escape //65307
# define KEY_LEFT XK_Left //65361
# define KEY_UP XK_Up //65362
# define KEY_RIGHT XK_Right //65363
# define KEY_DOWN XK_Down //65364
# define KEY_PG_UP XK_Page_Up //65365
# define KEY_PG_DOWN XK_Page_Down //65366
# define KEY_PLUS XK_equal //61
# define KEY_MINUS XK_minus //45
# define KEY_SPACE XK_space //32
# define KEY_P XK_p //70
# define KEY_A XK_a //61
# define KEY_W XK_w //77
# define KEY_D XK_d //64
# define KEY_S XK_s //73
# define KEY_X XK_x //78

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}			t_point;

typedef struct s_data
{
	t_mlx	*mlx;
	t_point	***map;
	int		tmp;
	int		col_size;
	int		row_size;
	int		anchor_x;
	int		anchor_y;
	int		x;
	int		y;
	int		x_offset;
	int		y_offset;
	int		bg;
	int		pov;
	int		sup;
	double	distance;
	double	height;
	double	zoom;
	double	x_y_coef;
	double	y_z_coef;
	double	z_x_coef;
}			t_data;
//map
void	*ft_map(t_data *data, char *filename);
size_t	ft_atohex(char *str);
void	*ft_free_doubleptr(void	**array);
int		ft_strlen_doubleptr(void **ptr);
t_point	*ft_getpoint(t_data *data, char *point);
t_point	**ft_getrow(t_data *data, char *map_row);
void	*ft_map_conversion(t_data *data, char *map);
void	*ft_read(int fd, char **map, char *buf);
t_data	*ft_map_work_helper(t_data *data, int i);
void	ft_map_work(t_data *data);
void	*ft_freemap(t_data *data);
void	*ft_validmap(char *map);
//map
//window
void	*ft_window(t_data *data);
int		ft_destroyhandler(t_mlx *mlx);
void	*ft_destroy_win(t_mlx *mlx);
int		ft_initimage_ptr(t_mlx *mlx);
int		ft_initwin_ptr(t_mlx *mlx);
//window
//render
void	ft_render(t_data *vars);
void	ft_rotate_zx(t_data *data, t_point *point);
void	ft_rotate_yz(t_data *data, t_point *point);
void	ft_rotate_xy(t_data *data, t_point *point);
void	ft_applypoint(t_point *point, int x, int y, int z);
void	ft_project_orthographic(t_data *data, t_point *point);
void	ft_transform_point(t_data *data, t_point *point);
void	ft_renderpixel(t_data *data, int x, int y, int color);
void	ft_linerender(t_data *data, t_point p1, t_point p2, int s);
void	ft_line(t_data *data, t_point p1, t_point p2, int color);
void	ft_drawlines(t_data *data, t_point *point, int state);
void	ft_background(t_data *data);
//render
//general
void	ft_startinit(t_data *data);
int		ft_keyhandler(int keycode, t_data *data);
void	ft_keyhandler_transform(int keycode, t_data *data);
//general

#endif