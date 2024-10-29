SRC = get_next_line.c get_next_line_utils.c get_next_line.h map_runner.c #replace map_runner with main.c to run its tests.
CFLAGS = -Wextra -Wall -Werror -g
all: $(SRC)
	cc $(CFLAGS) -D BUFFER_SIZE=1000000 $(SRC)
	

clean:
	rm -f get_next_line.h.gch

fclean: clean
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re