
NAME			= so_long
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
MLXFLAG			= -Lminilibx-linux/ -lmlx -lXext -lX11 -lm

UTILS_DIR		= utils
GNL_DIR			= utils/get_next_line
PRINTF_DIR		= utils/ft_printf

UTILS_SRC		= $(UTILS_DIR)

GNL_SRC			= $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
PRINTF_SRC		= $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_printf_utils.c

MAIN_SRC		= so_long.c

SRC				= $(MAIN_SRC) $(UTILS_SRC) $(GNL_SRC) $(PRINTF_SRC)
OBJ				= $(SRC:.c=.o)

INC				= includes/so_long.h $(GNL_DIR)/get_next_line.h $(PRINTF_DIR)/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
