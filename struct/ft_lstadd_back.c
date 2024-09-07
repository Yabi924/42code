#include "struct.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;

    last = *lst;
    if (last && new)
    {
        while (last->next)
            last = last->next;
        last->next = new;
    }
}

int main()
{
    t_list *node1 = ft_lstnew("omg");
    t_list *node2 = ft_lstnew("is");
    t_list *node3 = ft_lstnew("xxxxx");

    ft_lstadd_back(&node1, node2);
    ft_lstadd_back(&node1, node3);

    printf("%s,%s,%s\n", (char *)node1->content, (char *)node1->next->content, (char *)node1->next->next->content);
  
    return 0;
}