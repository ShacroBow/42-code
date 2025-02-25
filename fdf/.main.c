#include "fdf.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		return EXIT_FAILURE;

	t_data data;
	data.map = NULL;
	data.x = 0;
	data.y = 0;
	ft_startinit(&data);
	data.row_size = 0;
	data.col_size = 0;
	// Call the map function
	if (ft_map(&data, argv[1]) == NULL) {
		printf("Error reading map file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	// Print the map for verification
	for (int i = 0; i <= data.col_size; i++) {
		for (int j = 0; j <= data.row_size; j++) {
			if (data.map[i][j]) {
				printf("([i%d][j%d][z%2d][cl%x][p%p])  ", i, j, data.map[i][j]->z, data.map[i][j]->color, data.map[i][j]);
			}
		}
			printf("\n");
	}

	// Free allocated memory
	ft_freemap(&data);
	return EXIT_SUCCESS;
}