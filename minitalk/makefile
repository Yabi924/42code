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

NAME = minitalk

DLIBFT = -Llibft -lft
DPRINTF = -Lft_printf -lftprintf

SRCS = server.c client.c
OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

ALL: NAME

NAME: server client

server:	server.o libft ft_printf
	${CC} ${CFLAGS} -o $@ $< ${DLIBFT} ${DPRINTF}

client:	client.o libft ft_printf
	${CC} ${CFLAGS} -o $@ $< ${DLIBFT} ${DPRINTF}

libft:
	make -C libft

ft_printf:
	make -C ft_printf

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all