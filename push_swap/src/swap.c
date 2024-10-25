#include "push_swap.h"

void    sa(t_stack *stack)
{
    index_swap(stack->stack_a, 0, 1);
    ft_printf("sa\n");
}

void    sb(t_stack *stack)
{
    index_swap(stack->stack_b, 0, 1);
    ft_printf("sb\n");
}

void    ss(t_stack *stack)
{
    index_swap(stack->stack_a, 0, 1);
    index_swap(stack->stack_b, 0, 1);
    ft_printf("ss\n");
}

// void    pb(t_stack *stack)
// {
//     int i;

//     i = 0;
//     stack->stack_b[0] = stack->stack_a[0];
//     while (i < stack->a_len - 1)
//     {
//         stack->stack_a[i] = stack->stack_a[i + 1];
//         i++;
//     }

//     stack->a_len--;
//     ft_printf("pb\n");
// }

// void    pa(t_stack *stack)
// {
//     int i;

//     i = 0;
//     stack->stack_a[0] = stack->stack_b[0];
//     while (i < stack->stack_len - 1)
//     {
//         stack->stack_b[i] = stack->stack_b[i + 1];
//         i++;
//     }
//     ft_printf("pa\n");
// }