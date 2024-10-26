#include "push_swap.h"

void    print_temp(int *n, int len)
{
    int i = 0;
    ft_printf("temp:");
    while (i < len)
    {
        if (n[i] < -100000000)
            ft_printf("\\0 ");
        else
            ft_printf("%d ", n[i]);
        i++;
    }
    ft_printf("\n");
}

void    print_a(t_stack *stack)
{
    int i = 0;
    ft_printf("a:");
    while (i < stack->a_len)
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
    ft_printf("b:");
    while (i < stack->b_len)
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
    ft_printf("a:%d b:%d\n", stack->a_len, stack->b_len);
    ft_printf("\n");
    print_ab(stack);
    ft_printf("\n");
    ra(stack);

    print_ab(stack);
}
