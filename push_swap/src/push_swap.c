#include "push_swap.h"

int check_bit(t_stack *stack, int b)
{
    int i;

    i = 0;
    while (i < stack->a_len)
    {
        if ((stack->stack_a[i] >> b) & 1)
            return (1);
        i++;
    }
    return (0);
}

void    radix_sort(t_stack *stack)
{
    int i;

    i = 0;
    while (check_bit(stack, i))
    {
        
    }
}

void    push_swap(t_stack *stack)
{
    indexing(stack);
    if (!is_sorted(stack))
    {
        if (stack->stack_len <= 5)
            hardcode(stack);
        else
            radix_sort(stack);
    }
    // ft_printf("is sort:%d\n", is_sorted(stack));
    free(stack->stack_a);
    free(stack->stack_b);
}