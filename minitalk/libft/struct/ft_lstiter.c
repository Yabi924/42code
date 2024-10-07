#include "struct.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void ftprint(void *lst)
{
    printf("%s\n", (char *)lst);
}

int main()
{
    t_list *node = ft_lstnew("hello");
    ft_lstadd_back(&node, ft_lstnew("good"));
    ft_lstadd_back(&node, ft_lstnew("morning"));
    ft_lstadd_back(&node, ft_lstnew("girl"));

    ft_lstiter(node, &ftprint);
    // printf("%s %s\n", (char *)node->content, (char *)node->next->content);
    return 0;
}
*/
