#include "get_next_line.h"

int main()
{
    int fd = open("/home/42code/test.txt", O_RDWR);
    // int fd = open("/Users/yyan-bin/Desktop/42code/test.txt", O_RDWR);
    // printf("main-fd:%d\n", fd);
    // char *str = ft_strdup("");
    // int readd = read(fd, str, BUFFER_SIZE);
    // printf("main-read:%d\n", readd);
    // printf("%s\n", str);

    char *line = get_next_line(fd);
    if (!line)
        printf("line is NULL\n");
    else
        printf("main:%s\n", line);  

    line = get_next_line(fd);
    if (!line)
        printf("line is NULL\n");
    else
        printf("main:%s\n", line); 

    line = get_next_line(fd);
    if (!line)
        printf("line is NULL\n");
    else
        printf("main:%s\n", line); 
     
    return 0;
}