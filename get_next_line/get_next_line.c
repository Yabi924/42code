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

    if (fd < 0 || !readtemp || BUFFER_SIZE <= 0)
        return NULL;
    while (fd)
    {
        if (ft_strchr(readtemp, '\n') == TRUE)
            break ;
        if (read(fd, newline, BUFFER_SIZE) == -1)
        {
            free(readtemp);
            return (NULL);
        }
        readtemp = ft_strjoin(readtemp, newline);
        
    }
    return (readtemp);
}

char    *line(char *save)
{
    char    *realline;
    int i;

    i = 0;
    if (!save)
        return (NULL);
    while (save[i] && save[i] != '\n')
        i++;
    realline = ft_substr(realline, 0, i);
    if (!realline)
        return (NULL);
    return (realline);
}

char *saving(char *save)
{
    int i;
    char *remain;

    i = 0;
    while (save[i] && save[i] != '\n')
        i++;
    remain = ft_substr(save, i, ft_strlen(save) - i);
    free(save);
    return (remain);
}

char *get_nex_line(int fd)
{
    static char *save;
    char *realline;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, save, 0) == 0)
        return (NULL);
    if (!save)
        save = ft_strdup("");
    save = get_the_line(fd, save);
    realline = line(save);
    save = saving(save);
    return (realline);
}