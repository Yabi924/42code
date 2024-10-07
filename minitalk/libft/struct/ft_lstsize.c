#include "struct.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
int main()
{
    t_list *node1 = ft_lstnew("omg");
    t_list *node2 = ft_lstnew("is");
    t_list *node3 = ft_lstnew("xxxxx");

    ft_lstadd_front(&node3, node2);
    ft_lstadd_front(&node2, node1);

    printf("%d\n", ft_lstsize(node1));
    printf("%s,%s,%s\n", (char *)node1->content/
    , (char *)node1->next->content/
    , (char *)node1->next->next->content);

    return 0;
}
*/
