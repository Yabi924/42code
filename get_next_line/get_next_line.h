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
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*cuting(char *save);
char	*readline(int fd, char *save);
char	*afterline(char *save);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif
