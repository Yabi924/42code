#include "struct.h"

void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (lst && del)
    {
        del(lst->content)
        free(lst);
    } 
}

/*
void del(t_list *node)
{
    free(node->content);
}

int main()
{
    t_list *node1 = ft_lstnew("omg");
    
    printf("%s\n", (char *)node1->content);

    ft_lstdelone(node1, del);
    if (!node1)
        printf("nothing");

    return 0;
}
*/