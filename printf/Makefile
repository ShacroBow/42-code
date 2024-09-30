NAME = libftprintf.a
TESTMAIN = main.c
SRC_DIR = ./src/
SRC = $(SRC_DIR)ft_printf.c $(SRC_DIR)ft_printf_utils.c \
	$(SRC_DIR)ft_itoa_unsigned.c $(SRC_DIR)ft_itohex.c
OBJ_DIR = ./obj/
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBFT_PATH = ./libft/
LIBFT =$(LIBFT_PATH)libft.a
CC = cc
AR = ar
ARFLAGS = -rcs
CFLAGS = -Wall -Wextra -Werror -Iinclude


all: $(NAME)

#bonus: all

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) -l $(LIBFT)

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

compile: $(NAME)
	$(CC) $(TESTMAIN) $(NAME) $(LIBFT) $(CFLAGS)

.PHONY: all clean fclean re compile #bonus