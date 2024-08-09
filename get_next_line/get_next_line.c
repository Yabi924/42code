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

char    *get_the_line(int fd, char *readtemp)
{
    char    *newline;
    int i;

    if (fd < 0 || !readtemp)
        return NULL;
    while (fd)
    {
        i = read(fd, newline, BUFFER_SIZE);
        if (i == -1)
        {
            free(readtemp);
        }
        readtemp = ft_strjoin(readtemp, newline);
        if (ft_strchr(readtemp, '\n') == TRUE)
            break ;
    }
    free(newline);
    return (readtemp);
}

char    *line(char *save)
{
    char *trueline;

}

char *get_nex_line(int fd)
{
    static char *save;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, save, 0) == 0)
        return (NULL);
    if (!save)
        save = ft_strdup("");
    save = get_the_line(fd, save);
}