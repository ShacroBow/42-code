#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "libft/libft.h"
# include <mlx.h>

//delete
# include <stdio.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include <X11/XKBlib.h>
//delete

# define BUFFER_SIZE 100
# define BG_COLOR 0x09090B
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_TITLE "FdF"
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PG_UP 65365
# define KEY_PG_DOWN 65366
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32
# define PADDED_WIDTH 1800
# define PADDED_HEIGHT 900

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
	int		col_size;
	int		row_size;
	int		anchor_x;
	int		anchor_y;
	int		x;
	int		y;
	double	distance;
	double	height;
	double	zoom;
	double	x_y_coef;
	double	y_z_coef;
	double	z_x_coef;
}			t_data;

void	*ft_map(t_data *data, char *filename);
void	*ft_freemap(t_data *data);
void	*ft_window(t_data *data);
void	ft_render(t_data *vars);
void	render_map(t_data *data);
void	draw_background(t_data *vars);

#endif