NAME			= so_long
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
MLXFLAG			= -Lmlx -lmlx -framework OpenGL -framework AppKit

UTILS_DIR		= utils
GNL_DIR			= utils/get_next_line
PRINTF_DIR		= utils/ft_printf

UTILS_SRC		= $(UTILS_DIR)/clean.c $(UTILS_DIR)/ft_strdup.c $(UTILS_DIR)/ft_strlcpy.c $(UTILS_DIR)/ft_strlen.c $(UTILS_DIR)/handle_errors.c $(UTILS_DIR)/map_matrice.c \
					$(UTILS_DIR)/parse_map.c $(UTILS_DIR)/setup_game.c $(UTILS_DIR)/setup_hooks.c $(UTILS_DIR)/strcmp.c $(UTILS_DIR)/valid_chars.c $(UTILS_DIR)/valid_map.c \
					$(UTILS_DIR)/valid_walls.c $(UTILS_DIR)/mov_player.c

GNL_SRC			= $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
PRINTF_SRC		= $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_printf_utils.c

MAIN_SRC		= so_long.c

SRC				= $(MAIN_SRC) $(UTILS_SRC) $(GNL_SRC) $(PRINTF_SRC)
OBJ				= $(SRC:.c=.o)

INC				= include/so_long.h include/path.h $(GNL_DIR)/get_next_line.h $(PRINTF_DIR)/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAG) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re