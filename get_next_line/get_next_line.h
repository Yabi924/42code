/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:32:48 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/08/09 18:32:52 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# define TRUE 1
# define FALSE 0

char    *get_next_line(int fd);
char    *cuting(char *save);
char    *readline(int fd, char *save);
char    *afterline(char *save);
size_t	ft_strlen(const char *s);
int     ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif