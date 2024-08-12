/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:33:34 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/08/09 18:33:35 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *readline(int fd, char *save)
{
    char *temp;
    int readd;

    temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (temp)
        return (NULL);
    temp[BUFFER_SIZE + 1] = '\0';
    readd = 1;
    while (ft_strchr(save, '\n') == TRUE && readd)
    {
        readd = read(fd, temp, BUFFER_SIZE);
        if (readd == -1)
        {
            free(temp);
            return (NULL);
        }
        save = ft_strjoin(save, temp);
    }
    return (save);
}


char *get_next_line(int fd)
{
    static char *save;
    char *line;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    save = readline(fd, save);

    return (line);
}