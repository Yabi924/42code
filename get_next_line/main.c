#include "get_next_line.h"

int main()
{
    int fd = open("/home/42code/test.txt", O_RDONLY);
    // int fd = open("/Users/yyan-bin/Desktop/42code/test.txt", O_RDWR);
    // printf("main-fd:%d\n", fd);
    // char *str = ft_strdup("");
    // int readd = read(fd, str, BUFFER_SIZE);
    // printf("main-read:%d\n", readd);
    // printf("%s\n", str);

    int i = 0;
    while (1)
    {
        // char *line = ft_gnl(fd);
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

    // char *line = get_next_line(fd);
    // if (!line)
    //     printf("line is NULL\n");
    // else
    //     printf("main-1:%s\n", line);  

    // line = get_next_line(fd);
    // if (!line)
    //     printf("line is NULL\n");
    // else
    //     printf("main-2:%s\n", line); 

    // line = get_next_line(fd);
    // if (!line)
    //     printf("line is NULL\n");
    // else
    //     printf("main-3:%s\n", line); 
     
    return 0;
}