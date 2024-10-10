CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
SRC = test.c
OJB = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OJB)

fclean: clean
	rm -f $(NAME)

re: fclean all
