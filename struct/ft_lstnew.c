#include "struct.h"

t_list   *ft_lstnew(void *content)
{
    t_list   *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

/*
int main()
{
    t_list *node = ft_lstnew("wtf");
    printf("%s\n", (char *)node->content);
    return 0;
}
*/