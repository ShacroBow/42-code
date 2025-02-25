#include "fdf.h"

size_t	ft_atohex(char *str)
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
		return (ft_free_doubleptr((void **)str_point), NULL);
	ret->x = data->x;
	ret->y = data->y;
	ret->z = ft_atoi(str_point[0]);
	if (len > 1 && str_point[1][0] == '0' && \
		(str_point[1][1] == 'x' || str_point[1][1] == 'X'))
		ret->color = ft_atohex((str_point[1] + 2));
	else
		ret->color = DEF_LINECOLOR;
	ft_free_doubleptr((void **)str_point);
	return (ret);
}

t_point	**ft_getrow(t_data *data, char *map_row)
{
	t_point			*point;
	char			**str_row;
	size_t			len;

	str_row = ft_split(map_row, ' ');
	if (!str_row)
		return (NULL);
	len = ft_strlen_doubleptr((void **)str_row);
	data->map[data->y] = ft_calloc((len + 1), sizeof(t_point **));
	if (!data->map[data->y])
		return (ft_free_doubleptr((void **)str_row), NULL);
	data->x = 0;
	while (str_row[data->x])
	{
		point = ft_getpoint(data, str_row[data->x]);
		if (point == NULL)
			return (ft_free_doubleptr((void **)data->map[data->y]), NULL);
		data->map[data->y][data->x] = point;
		data->x += 1;
	}
	data->map[data->y][len] = NULL;
	ft_free_doubleptr((void **)str_row);
	return (data->map[data->y]);
}
