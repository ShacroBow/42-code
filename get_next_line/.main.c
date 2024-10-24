#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"


int main(void)
{
	int fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 1;
	}

	char *line;
	int i=0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line %d printed: %s",i, line);
		free(line);
		i++;
	}
	if (!line)
	{
		printf("\nover: %s\n", line);
	}
	close(fd);
	return 0;
}