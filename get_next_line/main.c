#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

int main()
{
    char *str;// = (char *)malloc(6 * sizeof(char));
    int fd = open("/Users/yyan-bin/Desktop/test.txt", O_RDWR);
    int i = read(fd, str, 300);
    write(fd, "\nwtf", 4);
    printf("%s\n", str);

    return 0;
}