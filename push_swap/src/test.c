#include "push_swap.h"

void    print_a(t_stack *stack)
{
    int i = 0;
    while (i < stack->stack_len)
    {
        if (stack->stack_a[i] < -100000000)
            ft_printf("\\0 ");
        else
            ft_printf("%d ", stack->stack_a[i]);
        i++;
    }
    ft_printf("\n");
}

void    print_b(t_stack *stack)
{
    int i = 0;
    while (i < stack->stack_len)
    {
        if (stack->stack_b[i] < -100000000)
            ft_printf("\\0 ");
        else
            ft_printf("%d ", stack->stack_b[i]);
        i++;
    }
    ft_printf("\n");
}

void    print_ab(t_stack *stack)
{
    print_a(stack);
    print_b(stack);
}

void    test(t_stack *stack)
{
    print_ab(stack);
    // pb(stack);
    sa(stack);
    print_ab(stack);
}