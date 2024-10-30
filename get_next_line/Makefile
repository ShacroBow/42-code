SRC = get_next_line.c get_next_line_utils.c get_next_line.h .main.c #replace map_runner with main.c to run its tests.
CFLAGS = -Wextra -Wall -Werror -g
SRC_bonus = get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.h .main.c
all: $(SRC)
	cc $(CFLAGS) -D BUFFER_SIZE=42 $(SRC)
	
bonus: $(SRC_bonus)
	cc $(CFLAGS) -D BUFFER_SIZE=42 $(SRC_bonus)

clean:
	rm -f get_next_line.h.gch get_next_line_bonus.h.gch

fclean: clean
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re bonus