SRC = get_next_line.c get_next_line_utils.c get_next_line.h main.c
CFLAGS = -Wextra -Wall -Werror -g
all: $(SRC)
	cc $(CFLAGS) -D BUFFER_SIZE=1 $(SRC)

.PHONY: all