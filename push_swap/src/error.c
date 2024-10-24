#include "push_swap.h"

void    free_arr(char **arr)
{
    int i;

    i = 0;
    if (arr)
    {
        while (arr[i])
            free(arr[i++]);
        free(arr);
    }
}

void    error(t_stack *stack, int f)
{
    if (f == 1)
    {
        ft_printf("error1\n");
        ft_printf("error\n");
        exit(0);
    }
    else if (f == 2)
    {
        if (stack->stack_a)
        {
            free(stack->stack_a);
            ft_printf("free A\n");
        }
        if (stack->stack_b)
        {
            free(stack->stack_b);
            ft_printf("free B\n");
        }
        ft_printf("error2\n");
        ft_printf("error\n");
        exit(0);
    }
}

void    error_free_arr(t_stack *stack, char **arr)
{
    free_arr(arr);
    error(stack, 2);
}
