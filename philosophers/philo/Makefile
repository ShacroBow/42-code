NAME = philo
SRC = main.c ft_philosopher.c ft_fat.c helper_functions.c ft_atoi.c ft_monitor_simulation.c
OBJ_DIR = ./dir/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g


all: $(NAME)

#bonus: $(NAME_BONUS)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT_PATH)$(LIBFT):
	make -C $(LIBFT_PATH) all -j8

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME) a.out $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re compile #bonus
