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

    newline = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!newline)
        return (NULL);
    while (fd)
    {
        if (ft_strchr(readtemp, '\n') == TRUE)
            break ;
        i = read(fd, newline, BUFFER_SIZE);
        if (i == -1)
        {
            printf("get_the_line=NULL");
            free(newline);
            free(readtemp);
            return (NULL);
        }
        newline[i] = '\0';
        printf("get_the_line:line=%s\n", newline);
        readtemp = ft_strjoin(readtemp, newline);
        // printf("get_the_line:readtemp=%s\n", readtemp);
    }
    free(newline);
    return (readtemp);
}

char    *line(char *save)
{
    char    *realline;
    int i;

    i = 0;
    // printf("save:%s\n", save);
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

char *get_next_line(int fd)
{
    // static char *save;
    char *save;
    char *realline;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
        return (NULL);
    if (!save)
        save = ft_strdup("");
    // printf("gnl:save=%s\n", save);
    save = get_the_line(fd, save);
    // printf("gnl:get_the_line:line=%s\n", save);
    realline = line(save);

    save = saving(save);
    return (realline);
}
