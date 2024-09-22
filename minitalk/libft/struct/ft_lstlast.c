#include "struct.h"

t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

/*
int main()
{
    t_list *node1 = ft_lstnew("omg");
    t_list *node2 = ft_lstnew("is");
    t_list *node3 = ft_lstnew("xxxxx");

    ft_lstadd_front(&node3, node2);
    ft_lstadd_front(&node2, node1);

    t_list *last = ft_lstlast(node1);
    printf("%s\n", (char *)last->content);
    
    return 0;
}
*/