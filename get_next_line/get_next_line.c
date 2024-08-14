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

//read .txt to string,if the string got '\n',return the string 
char	*readline(int fd, char *save)
{
	char	*temp;
	int		readd;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	readd = 1;
	while (ft_strchr(save) == FALSE && readd)
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
	if (!ft_strlen(save))
		save = NULL;
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
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
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

//cut first line '\n' and return remainder string
char	*afterline(char *save)
{
	char	*afline;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	afline = (char *)malloc(sizeof(char) * (ft_strlen(save) - i));
	if (!afline)
		return (NULL);
	while (save[++i])
		afline[j++] = save[i];
	afline[j] = '\0';
	free(save);
	return (afline);
}

//read--take first line--cut first line and save remainder
char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	save = readline(fd, save);
	line = cuting(save);
	save = afterline(save);
	return (line);
}

/*
int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR);
    char    *s = (char *)malloc(sizeof(char) * 10);
    int readd = read(fd, s, 10);
    if (readd == 0)
    {
        char c = 'a';
        while (c <= 'z') {
            if (c == 'e' || c == 'l' || c == 's' || c == 'x')
                write(fd, "\n", 1);
            write(fd, &c, 1);
            c++;
        }
    }
    free(s);
    close(fd);

    fd = open("/home/42code/get_next_line/test.txt", O_RDONLY);
    int i = 1;
    while (i)
    {
        char *line = get_next_line(fd);
        if (line)
            printf("main-%d:%s\n", i, line);
        else
        {
            printf("NULL\n");
            free(line);
            break ;
        }
        i++;
    }
    close(fd);
    return 0;
}
*/
