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
    if (!temp)
        return (NULL);
    readd = 1;
    while (!ft_strchr(save, '\n') && readd)
    { 
        readd = read(fd, temp, BUFFER_SIZE);
        if (readd == -1)
        {
            free(temp);
            return (NULL);
        }
        temp[readd] = '\0';
        save = ft_strjoin(save, temp);
    }
    return (save);
}

char    *cuting(char *save)
{
    if (!save)
        return (NULL);
    char    *line;
    int i;
    int j;

    i = 0;
    j = 0;    
    while (save[i] && save[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 1));
    if (!line)
        return (NULL);
    while (j < (i + 1))
    {
        line[j] = save[j];
        j++;
    }
    line[j] = '\0';
    return (line);
}

char *afterline(char *save)
{
    char *afline;
    int ttl;
    int i;
    int j;

    ttl = ft_strlen(save);
    i = 0;
    j = 0;
    while (save[i] || save[i] != '\n')
        i++;
    afline = (char *)malloc(sizeof(char) * (ttl - i + 1));
    if (!afline)
        return (NULL);
    while (save[i])
    {
        afline[j++] = save[i++];
    }
    afline = '\0';
    // free(save);
    return (afline);
}

char *get_next_line(int fd)
{
    static char *save;
    char *line;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    save = readline(fd, save);
    line = cuting(save);
    save = afterline(save);
    return (line);
}