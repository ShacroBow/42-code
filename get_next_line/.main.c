#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"


int main(void)
{
	// int fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
	// int fd = open("files/alternate_line_nl_with_nl", O_RDONLY);
	// int fd = open("files/43_no_nl", O_RDONLY);
	// int fd = open("files/multiple_nl.txt", O_RDONLY);
	int fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 1;
	}

	char *line;
	int i=0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line %2d printed: %s",i, line);
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