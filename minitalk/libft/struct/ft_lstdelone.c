#include "struct.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

/*
#include <string.h>
void del(void *content)
{
    free(content);
}

int main()
{
    t_list *node1 = ft_lstnew(strdup("omg"));
    
    printf("%s\n", (char *)node1->content);

    ft_lstdelone(node1, del);
    if (!node1)
        printf("nothing");
    else
        printf("ehhh");
    return 0;
}
*/
