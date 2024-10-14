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
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(MLX_PATH)
	make -C $(LFT_PATH)
	$(CC) $(OBJ) -o $(NAME) main.c $(PATH_LIB) $(LFLAGS)

clean:
	rm -f $(OJB)

fclean: clean
	rm -f $(NAME)

re: fclean all
