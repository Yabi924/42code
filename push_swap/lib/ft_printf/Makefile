CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC = ft_printf.c printc.c prints.c printd.c printu.c printhex.c \
	printp.c
OJB = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OJB)
	@ar rcs $(NAME) $(OJB)

%.o: %.c
	@$(CC) $(CFLAG) -c $< -o $@

clean:
	@rm -f $(OJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all
