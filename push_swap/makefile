CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
NAME = push_swap

SRCS = src/main.c \
	src/swap.c \
	src/error.c \
	src/init_arr.c \
	src/checking.c \
	src/utails.c \
	src/push_swap.c \
	src/test.c

OBJS = $(SRCS:src/%.c=src/%.o)

LIBS = $(PATH_LIB) -L./lib/ft_printf -lftprintf -L./lib/libft -lft

LIBFT_PATH = ./lib/libft/libft.a
PF_PATH = ./lib/ft_printf/libftprintf.a

PATH_LIB = $(LIBFT_PATH) $(PF_PATH)

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(CFLAGS) -o $(NAME) $(OBJS) $(PATH_LIB) $(LIB_FLAG)
	@echo "Hello push_swap"
	@make clean --no-print-directory

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

ft:
	@make -C ./lib/ft_printf --no-print-directory
	@make -C ./lib/libft --no-print-directory
	@echo "Hello! libft & ft_printf"

clean:
	@rm -f $(OBJS)
	@echo "bye objs"

fclean: clean
	@rm -f $(NAME)
	@echo "bye $(NAME)"

cleanl:
	@make clean -C ./lib/ft_printf --no-print-directory
	@make clean -C ./lib/libft --no-print-directory
	@echo "clean obj libft & ft_printf"

fcleanl:
	@make fclean -C ./lib/ft_printf --no-print-directory
	@make fclean -C ./lib/libft --no-print-directory
	@echo "fclean libft & ft_printf"

re: fclean all