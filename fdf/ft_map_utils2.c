#include "fdf.h"

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
			return (ft_free_doubleptr((void **)str_map), \
					ft_freemap(data), NULL);
		i++;
	}
	data->map[len] = NULL;
	return (ft_free_doubleptr((void **)str_map), data->map);
}

void	*ft_read(int fd, char **map, char *buf)
{
	int		readlen;
	char	*tmp;

	readlen = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
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

t_data	*ft_map_work_helper(t_data *data, int i)
{
	int	j;

	j = 0;
	while (i > 0)
	{
		i--;
		if (data->map[i][data->row_size + 1] != NULL)
		{
			j = 1;
			while (data->map[i][data->row_size + j])
			{
				free(data->map[i][data->row_size + j]);
				data->map[i][data->row_size + j] = NULL;
				j++;
			}
		}
	}
	return (data);
}

void	ft_map_work(t_data *data)
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
	data = ft_map_work_helper(data, i);
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
