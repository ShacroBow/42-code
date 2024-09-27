NAME = libftprintf.a
SRC_DIR = ./src/
SRC = $(SRC_DIR)main.c
OBJ_DIR = ./obj/
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBFT_PATH = ./libft/
LIBFT =$(LIBFT_PATH)libft.a
CC = cc
AR = ar
ARFLAGS = -rcs
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

#bonus: all

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(LIBFT)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME) a.out $(OBJ_DIR)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re #bonus