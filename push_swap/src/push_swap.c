#include "push_swap.h"

void    push_swap(t_stack *stack)
{
    indexing(stack);
    if (!is_shorted(stack))
    {
        if (stack->stack_len <= 5)
            hardcode(stack);
    }
    free(stack->stack_a);
    free(stack->stack_b);
}