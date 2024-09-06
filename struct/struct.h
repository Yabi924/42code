#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
    void    *content;
    struct s_list   *next;
}   t_list;

t_list  *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);

#endif