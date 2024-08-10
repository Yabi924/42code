#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char *test(char *s)
{
    char *ss;

    ss = "abcd";
    s = "a";
    return (ss);
}

int main()
{
    // char *str;// = (char *)malloc(6 * sizeof(char));
    // int fd = open("/Users/yyan-bin/Desktop/test.txt", O_RDWR);
    // int i = read(fd, str, 300);
    // write(fd, "\nwtf", 4);
    // printf("%s\n", str);
    printf("%s\n", test("d"));

    return 0;
}