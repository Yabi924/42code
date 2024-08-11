#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("/home/42code/test.txt", O_RDWR);
    char *line = get_next_line(fd);
    printf("%s\n", line);   
    
    return 0;

}