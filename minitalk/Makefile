NAME_CLIENT = client
NAME_SERVER = server
SRC_CLIENT = ft_client.c utils.c
SRC_SERVER = ft_server.c utils.c
SRC_CLIENT_BONUS = ft_client_bonus.c utils_bonus.c
SRC_SERVER_BONUS = ft_server_bonus.c utils_bonus.c
OBJ_DIR = ./dir/
OBJ_CLIENT = $(SRC_CLIENT:%.c=$(OBJ_DIR)%.o)
OBJ_SERVER = $(SRC_SERVER:%.c=$(OBJ_DIR)%.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:%.c=$(OBJ_DIR)%.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:%.c=$(OBJ_DIR)%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address,undefined -pedantic

all: $(NAME_CLIENT)

bonus: $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_DIR) $(OBJ_CLIENT) $(OBJ_SERVER)
	$(CC) $(OBJ_CLIENT) $(CFLAGS) -o $(NAME_CLIENT)
	$(CC) $(OBJ_SERVER) $(CFLAGS) -o $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_DIR) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	$(CC) $(OBJ_CLIENT_BONUS) $(CFLAGS) -o $(NAME_CLIENT)
	$(CC) $(OBJ_SERVER_BONUS) $(CFLAGS) -o $(NAME_SERVER)

$(OBJ_DIR)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER) a.out $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re compile bonus
