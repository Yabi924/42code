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

SRC = main.c

OBJ = $(SRC:%.c=obj/%.o)

MLX_PATH = ./lib/minilibx/
LFT_PATH = ./lib/libft/libft.a
PF_PATH = ./lib/ft_printf/ftprintf.a

PATH_LIB = -L$(MLX_PATH) -L$(LFT_PATH) -L$(PF_PATH)

all: obj $(NAME)

obj:
	@mkdir -p obj

obj/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) $(LFLAGS) -o $(NAME)
	@echo "Hello! $(NAME)"

ft:
	@make -C ./lib/libft
	@make -C ./lib/ft_printf
	@echo "make libft & ft_printf"

mlx:
	@make -C ./lib/minilibx
	@echo "make mlx"

clean:
	@rm -rf ./obj/
	@echo "clean obj"

fclean: clean
	@rm -rf $(NAME)
	@echo "clean $(NAME)"

cleanl:
	@make clean -C ./lib/libft
	@make clean -C ./lib/ft_printf
	@echo "clean obj libft & ft_printf"

fcleanl: fclean
	@make fclean -C ./lib/libft
	@make fclean -C ./lib/ft_printf
	@echo "clean libft.a & ft_printf.a"

fcm: fcleanl
	@make clean -C ./lib/minilibx
	@echo "clean mlx.a"

re: fclean all
