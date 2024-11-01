#include "push_swap.h"

void    copy_to_a_after_free(t_stack *stack, int *copy)
{
    int i;

    i = -1;
    while (++i < stack->a_len)
        stack->stack_a[i] = copy[i];
    free(copy);
}