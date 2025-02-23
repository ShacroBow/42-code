#include "fdf.h"

unsigned int	ft_atohex(char *str)
{
	unsigned int	res;
	int				val;

	res = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			val = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			val = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			val = *str - 'A' + 10;
		res = res * 16 + val;
		str++;
	}
	return (res);
}

void	*ft_free_doubleptr(void	**array)
{
	size_t	i;

	i = 0;
	if (array == NULL)
		return (NULL);
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
	return (NULL);
}

int	ft_strlen_doubleptr(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}

t_point	*ft_getpoint(t_data *data, char *point)
{
	t_point	*ret;
	char	**str_point;
	int		len;

	str_point = ft_split(point, ',');
	if (!str_point)
		return (NULL);
	len = ft_strlen_doubleptr((void **)str_point);
	ret = ft_calloc((1), sizeof(t_point));
	if (!ret)
		return (ft_free_doubleptr((void **)str_point));
	ret->x = data->x;
	ret->y = data->y;
	ret->z = ft_atoi(str_point[0]);
	if (len > 1)
		ret->color = ft_atohex((str_point[1] + 2));
	else
		ret->color = 16777215;
	ft_free_doubleptr((void **)str_point);
	data->x += 1;
	return (ret);
}

t_point	**ft_getrow(t_data *data, char *map_row)
{
	t_point			*point;
	char			**str_row;
	size_t			row_len;
	size_t			i;

	str_row = ft_split(map_row, ' ');
	if (!str_row)
		return (NULL);
	row_len = ft_strlen_doubleptr((void **)str_row);
	data->map[data->y] = ft_calloc((row_len + 1), sizeof(t_point **));
	if (!data->map[data->y])
		return (ft_free_doubleptr((void **)str_row), NULL);
	i = 0;
	while (str_row[i])
	{
		point = ft_getpoint(data, str_row[i]);
		if (point == NULL)
			return (ft_free_doubleptr((void **)data->map[data->y]), NULL);
		data->map[data->y][i] = point;
		i++;
	}
	data->map[data->y][row_len] = NULL;
	ft_free_doubleptr((void **)str_row);
	return (data->map[data->y]);
}

void	*ft_map_conversion(t_data *data, char *map)
{
	char	**str_map;
	size_t	len;
	size_t	i;

	str_map = ft_split(map, '\n');
	if (!str_map)
		return (NULL);
	len = ft_strlen_doubleptr((void **)str_map);
	data->map = ft_calloc((len + 1), sizeof(t_point ***));
	if (!data->map)
		return (ft_free_doubleptr((void **)str_map), NULL);
	i = 0;
	while (str_map[i])
	{
		data->y = i;
		data->map[i] = ft_getrow(data, str_map[i]);
		if (data->map[i] == NULL)
		{
			ft_free_doubleptr((void **)(void **)data->map);
			break ;
		}
		i++;
	}
	data->map[len] = NULL;
	return (ft_free_doubleptr((void **)str_map), data->map);
}

static void	*ft_read(int fd, char **map, char *buf)
{
	int		readlen;
	char	*tmp;

	readlen = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (readlen > 0)
	{
		readlen = read(fd, buf, BUFFER_SIZE);
		if (readlen == -1)
		{
			if (!(*map))
				free(*map);
			return (*map = NULL, free(buf), NULL);
		}
		buf[readlen] = '\0';
		tmp = ft_strjoin(*map, buf);
		if (*map)
			free(*map);
		*map = tmp;
		if (!tmp)
			return (free(buf), NULL);
	}
	return (free(buf), *map);
}

static void	ft_map_work(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j + 1] == NULL)
			{
				if (data->row_size > j || data->row_size == 0)
					data->row_size = j;
			}
			j++;
		}
		if (data->map[i + 1] == NULL)
			data->col_size = i;
		i++;
	}
	data->anchor_x = data->row_size / 2;
	data->anchor_y = data->col_size / 2;
}

void	*ft_freemap(t_data *data)
{
	size_t	i;
	size_t	j;
	t_point	***map;

	i = 0;
	j = 0;
	map = data->map;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != NULL)
		{
			free(map[i][j]);
			map[i][j] = NULL;
			j++;
		}
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	i = 0;
	free(data->map);
	data->map = NULL;
	return (NULL);
}

void	*ft_map(t_data *data, char *filename)
{
	char	*map;
	char	*buf;
	int		fd;

	map = NULL;
	buf = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ft_read(fd, &map, buf);
	close(fd);
	if (!map)
		return (NULL);
	data->map = ft_map_conversion(data, map);
	if (!(data->map))
		return (NULL);
	free(map);
	ft_map_work(data);
	return (data);
}
// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return EXIT_FAILURE;

// 	t_data data;
// 	data.map = NULL;
// 	data.x = 0;
// 	data.y = 0;
// 	data.row_size = 0;
// 	data.col_size = 0;
// 	// Call the map function
// 	if (ft_map(&data, argv[1]) == NULL) {
// 		printf("Error reading map file: %s\n", argv[1]);
// 		return EXIT_FAILURE;
// 	}

// 	// Print the map for verification
// 	for (int i = 0; i <= data.col_size; i++) {
// 		for (int j = 0; j <= data.row_size; j++) {
// 			if (data.map[i][j]) {
// 				printf("Point[%2d][%2d]: z = %2d, color = %x\n", \
// i, j, data.map[i][j]->z, data.map[i][j]->color);
// 			}
// 		}
// 	}

// 	// Free allocated memory
// 	ft_freemap(&data);
// 	return EXIT_SUCCESS;
// }