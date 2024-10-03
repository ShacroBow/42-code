NAME = libftprintf.a
TESTMAIN = .main.c
SRC_DIR = ./src/
SRC = $(SRC_DIR)ft_printf.c $(SRC_DIR)ft_printf_utils.c \
	$(SRC_DIR)ft_uitoa.c $(SRC_DIR)ft_itohex.c \
	 $(SRC_DIR)ft_printf_utils2.c $(SRC_DIR)ft_failcheck_printf.c
OBJ_DIR = ./obj/
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBFT_PATH = ./libft/
LIBFT = libft.a
CC = cc
AR = ar
ARFLAGS = -rcs
CFLAGS = -Wall -Wextra -Werror -I include


all: $(NAME)

#bonus: all

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT_PATH)$(LIBFT)
	cp $(LIBFT_PATH)$(LIBFT) ./
	mv $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
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

compile: $(NAME)
	$(CC) $(TESTMAIN) $(NAME) $(CFLAGS) -g

.PHONY: all clean fclean re compile #bonus