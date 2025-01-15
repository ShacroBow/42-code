NAME = push_swap
SRC = ft_parse_arguments.c ft_parse_string.c ft_print.c ft_pushswap.c \
ft_radixposition.c main.c utils1.c utils2.c utils3.c utils4.c
OBJ_DIR = ./dir/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)
LIBFT_PATH = ./libft/
LIBFT = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g


all: $(NAME)

#bonus: all

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT_PATH)$(LIBFT)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME) -L. $(LIBFT_PATH)$(LIBFT)

$(OBJ_DIR)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT_PATH)$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME) a.out $(OBJ_DIR)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re compile #bonus