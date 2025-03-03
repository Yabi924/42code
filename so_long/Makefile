SYS := $(shell uname -s)

ifeq ($(SYS), Linux)
	LFLAGS = -lmlx -lmlx_Linux -lX11 -lXext -lm
	LIBS = $(PATH_LIB) -L./lib/libft -lft -L./lib/ft_printf -lftprintf
else ifeq ($(SYS), Darwin)
	LFLAGS = -lmlx -framework OpenGL -framework AppKit
	LIBS = $(LFT_PATH) $(PF_PATH) -L./lib/libft -lft -L./lib/ft_printf -lftprintf
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

NAME = so_long

SRC = srcs/main.c \
	srcs/map_handle.c \
	srcs/exit.c \
	srcs/img_loop.c \
	srcs/flood_fill.c \
	srcs/moving.c \
	srcs/other.c

OBJ = $(SRC:srcs/%.c=srcs/%.o)

MLX_PATH = ./lib/minilibx-linux/
LFT_PATH = ./lib/libft/libft.a
PF_PATH = ./lib/ft_printf/libftprintf.a

PATH_LIB = -L$(MLX_PATH) -L$(LFT_PATH) -L$(PF_PATH)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LFLAGS) -o $(NAME)
	@echo "Hello! $(NAME)"

ft:
	@make -C ./lib/libft --no-print-directory
	@make -C ./lib/ft_printf --no-print-directory
	@echo "make libft & ft_printf"

mlx:
	@make -C ./lib/minilibx-linux --no-print-directory
	@echo "make mlx"

clean:
	@rm -rf $(OBJ)
	@echo "clean obj"

fclean: clean
	@rm -rf $(NAME)
	@echo "clean $(NAME)"

cleanl:
	@make clean -C ./lib/libft --no-print-directory
	@make clean -C ./lib/ft_printf --no-print-directory
	@echo "clean obj libft & ft_printf"

fcleanl: fclean
	@make fclean -C ./lib/libft --no-print-directory
	@make fclean -C ./lib/ft_printf --no-print-directory
	@echo "fclean libft.a & ft_printf.a & so_long"

cleanmlx: fcleanl
	@make clean -C ./lib/minilibx-linux --no-print-directory
	@echo "clean mlx.a"

re: fclean all
