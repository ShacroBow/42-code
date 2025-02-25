#include "fdf.h"

void	*ft_validmap(char *map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map);
	if (len > INT_MAX)
		return (NULL);
	while (ft_isalnum(map[i]) || map[i] == ',' || map[i] == '-' || \
			ft_isspace(map[i]))
	{
		if (ft_isalpha(map[i]) && !((map[i] >= 65 && map[i] <= 70) || \
		(map[i] >= 97 && map[i] <= 102) || map[i] == 'X' || map[i] == 'x'))
			break ;
		i++;
	}
	if ((int)len == i)
		return (map);
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
	if (map[0] == '\0' || !ft_validmap(map))
		return (free(map), map = NULL, NULL);
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