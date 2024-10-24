SRC = get_next_line.c get_next_line_utils.c get_next_line.h .main.c
CFLAGS = -Wextra -Wall -Werror -g
all: $(SRC)
	cc $(CFLAGS) -D BUFFER_SIZE=42 $(SRC)

clean:
	rm -f get_next_line.h.gch

fclean: clean
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re