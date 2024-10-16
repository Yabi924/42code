SYS := $(shell uname -s)

ifeq ($(SYS), Linux)
	LFLAGS = -lmlx -lmlx_Linux -lX11 -lXext -lm
	LIBS = $(PATH_LIB)
else ifeq ($(SYS), Darwin)
	LFLAGS = -lmlx -framework OpenGL -framework AppKit
	LIBS = $(LFT_PATH)
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC = srcs/main.c

OBJ = $(SRC:srcs/%.c=srcs/%.o)

MLX_PATH = ./lib/minilibx/
LFT_PATH = ./lib/libft/libft.a
PF_PATH = ./lib/ft_printf/ftprintf.a

PATH_LIB = -L$(MLX_PATH) -L$(LFT_PATH) -L$(PF_PATH)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) $(LFLAGS) -o $(NAME)
	@echo "Hello! $(NAME)"

ft:
	@make -C ./lib/libft --no-print-directory
	@make -C ./lib/ft_printf --no-print-directory
	@echo "make libft & ft_printf"

mlx:
	@make -C ./lib/minilibx --no-print-directory
	@echo "make mlx"

clean:
	@rm -rf srcs/%.o
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
	@make clean -C ./lib/minilibx --no-print-directory
	@echo "clean mlx.a"

re: fclean all
