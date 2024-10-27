#include "push_swap.h"

int count_n(t_stack *stack)
{
    int i;
    int *temp;

    i = 8;
    temp = copy_stack(stack->stack_a, stack->a_len);
    bb_sort(temp, stack->a_len);
    while (i >= 0)
    {
        if ((temp[stack->a_len - 1] >> i) & 1)
            break ;
        i--;
    }
    free(temp);
    return (i + 1);
}

int check_bit(int n, int b)
{
    if ((n >> b) & 1)
        return (1);
    return (0);
}

void    radix_sort(t_stack *stack)
{
    // int i;
    int len;

    // i = 0;
    len = count_n(stack);
    printf("a_len:%d %d\n", stack->a_len, len);
    // while (i <= len)
    // {
    //     if (check_bit(stack->stack_a[i], i))
    //         pb(stack);
    //     else
    //         ra(stack);
    //     while (stack->b_len != 0)
    //         pa(stack);
    //     i++;
    // }
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
    ft_printf("is sort:%d\n", is_sorted(stack));
    free(stack->stack_a);
    free(stack->stack_b);
}