#include "push_swap.h"

void    sa(t_stack *stack)
{
    int temp;

    temp = stack->stack_a[0];
    stack->stack_a[0] = stack->stack_a[1];
    stack->stack_a[1] = temp;
}

