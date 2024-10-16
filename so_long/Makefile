CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lft -lmlx -lmlx_Linux -lX11 -lXext -lm

NAME = so_long

SRC = test.c

OBJ = $(SRC:.c=.o)

LIB = ./lib/

MLX_PATH = $(LIB)minilibx/
LFT_PATH = $(LIB)libft

PATH_LIB = -L$(MLX_PATH) -L$(LFT_PATH)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -C $(MLX_PATH) --no-print-directory
	@make -C $(LFT_PATH) --no-print-directory
	@$(CC) -g $(OBJ) -o $(NAME) main.c $(PATH_LIB) $(LFLAGS)
	@mkdir obj
	@mv $(OBJ) obj
	@echo "Hello! $(NAME)"

clean:
	@rm -rf ./obj/
	@echo "clean obj"

fclean: clean
	@rm -rf $(NAME)
	@echo "clean $(NAME)"

re: fclean all
