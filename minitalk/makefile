# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 13:09:36 by yyan-bin          #+#    #+#              #
#    Updated: 2024/09/22 13:09:38 by yyan-bin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

DLIBFT = -L./libft -lft
DPRINTF = -L./ft_printf -lftprintf

libft = make -C libft
ft_printf = make -C ft_printf

SRCS = server.c client.c
OBJS = $(SRCS:%.c=%.o)

ALL: server client

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

server:	server.o
	${libft}
	${ft_printf}
	${CC} ${CFLAGS} -o server server.o ${DLIBFT} ${DPRINTF}

client:	client.o
	${libft}
	${ft_printf}
	${CC} ${CFLAGS} -o client client.o ${DLIBFT} ${DPRINTF}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f client server

cleanl: clean
	make clean -C libft
	make clean -C ft_printf

fcleanl: cleanl fclean
	make fclean -C libft
	make fclean -C ft_printf

re:	fcleanl ALL