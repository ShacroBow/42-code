#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"


int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 1;
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line printed: %s", line);
		free(line);
	}

	close(fd);
	return 0;
}