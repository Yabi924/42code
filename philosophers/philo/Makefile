CFLAGS = -Wall -Wextra -Werror -pthread #-g3 -fsanitize=address

NAME = philo

SRCS = main.c \
	utils.c \
	philo_life.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) 

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all