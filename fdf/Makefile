NAME = fdf
NAME_BONUS = fdf_bonus
SRC = main.c ft_window.c ft_map.c ft_render.c ft_map_utils1.c ft_map_utils2.c \
	ft_other.c ft_render_utils1.c ft_render_utils2.c
OBJ_DIR = ./dir/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)
SRC_BONUS = main_bonus.c ft_window_bonus.c ft_map_bonus.c ft_render_bonus.c \
	ft_map_utils1_bonus.c ft_map_utils2_bonus.c ft_other_bonus.c \
	ft_render_utils1_bonus.c ft_render_utils2_bonus.c
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)%.o)
LIBFT_PATH = ./libft/
LIBFT = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFLAGS = -lmlx -lX11 -lXext -lm


all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT_PATH)$(LIBFT)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME) -L. $(LIBFT_PATH)$(LIBFT) $(LIBFLAGS)

$(NAME_BONUS): $(OBJ_DIR) $(OBJ_BONUS) $(LIBFT_PATH)$(LIBFT)
	$(CC) $(OBJ_BONUS) $(CFLAGS) -o $(NAME_BONUS) -L. $(LIBFT_PATH)$(LIBFT) $(LIBFLAGS)

$(OBJ_DIR)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT_PATH)$(LIBFT):
	make -C $(LIBFT_PATH) all -j8

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS) a.out $(OBJ_DIR)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re compile #bonus
