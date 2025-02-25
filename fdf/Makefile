NAME = fdf
SRC = main.c ft_window.c ft_map.c ft_render.c ft_map_utils1.c ft_map_utils2.c \
	ft_other.c ft_render_utils1.c ft_render_utils2.c
OBJ_DIR = ./dir/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)
LIBFT_PATH = ./libft/
LIBFT = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFLAGS = -lmlx -lX11 -lXext -lm


all: $(NAME)

#bonus: all

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT_PATH)$(LIBFT)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME) -L. $(LIBFT_PATH)$(LIBFT) $(LIBFLAGS)

$(OBJ_DIR)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT_PATH)$(LIBFT):
	make -C $(LIBFT_PATH) all -j8

clean:
	rm -f $(OBJ_DIR)$(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME) a.out $(OBJ_DIR)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re compile #bonus
