/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:39:50 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/08/19 18:39:55 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_joinfree(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (s);
}

//read .txt to string,if the string got '\n',return the string 
char	*readline(int fd, char *save)
{
	char	*temp;
	int		readd;

	if (!save)
		save = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readd = 1;
	while (!ft_strchr(save, '\n') && readd > 0)
	{
		readd = read(fd, temp, BUFFER_SIZE);
		if (readd == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[readd] = '\0';
		save = ft_joinfree(save, temp);
	}
	if (temp)
		free(temp);
	return (save);
}

//get the first '\n' and return the string
char	*cuting(char *save)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	while (save[j] && save[j] != '\n')
	{
		line[j] = save[j];
		j++;
	}
	if (save[j] && save[j] == '\n')
		line[j] = '\n';
	return (line);
}

//cut first line '\n' and return remainder string
char	*afterline(char *save)
{
	char	*afline;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	afline = ft_calloc(ft_strlen(save) - i + 1, sizeof(char));
	while (save[++i])
		afline[j++] = save[i];
	free(save);
	return (afline);
}

//read--take first line--cut first line and save remainder
char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save[fd] = readline(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = cuting(save[fd]);
	save[fd] = afterline(save[fd]);
	return (line);
}

/*
int main()
{
    char c = 'a';
    int fd1 = open("test1.txt", O_CREAT | O_RDWR, 0644);
    char    *s = (char *)malloc(sizeof(char) * 10);
    int readd1 = read(fd1, s, 10);
    if (readd1 == 0)
    {
            while (c <= 'z')
        {
            if (c == 'e' || c == 'l' || c == 's' || c == 'x')
                write(fd1, "\n", 1);
            write(fd1, &c, 1);
            c++;
        }
    }
    free(s);
    close(fd1);

    int fd2 = open("test2.txt", O_CREAT | O_RDWR, 0644);
    char    *ss = (char *)malloc(sizeof(char) * 10);
    int readd2 = read(fd2, ss, 10);
    if (readd2 == 0)
    {
        while (c > 'a')
        {
            c--;
            if (c == 'e' || c == 'l' || c == 's' || c == 'x')
                write(fd2, "\n", 1);
            write(fd2, &c, 1);
        }
    }
    free(ss);
    close(fd2);

    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    int i = 1;
    while (i < 10)
    {
        // test1
        char *line1 = get_next_line(fd1);
        if (line1)
            printf("main1-%d:%s\n", i, line1);
        else
        {
            printf("test1:NULL\n");
            free(line1);
        }
        // test2
        char *line2 = get_next_line(fd2);    
        if (line2)
            printf("main2-%d:%s\n", i, line2);
        else
        {
            printf("test2:NULL\n");
            free(line2);
        }
        i++;
    }
    close(fd1);
    close(fd2);
    return 0;
}
*/
