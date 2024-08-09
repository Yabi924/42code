#include "get_next_line"

char *get(int fd)
{
    static char *temp;
    char *theline;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    read(fd, temp, BUFFER_SIZE);
    theline = ft_strchr(temp, '\n');
    
}

char *get_nex_line(int fd)
{
    
}