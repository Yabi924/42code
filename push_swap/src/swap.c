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

void    pa(t_stack *stack)
{
    int i;

    i = stack->a_len + 1;
    while (--i > 0)
        index_swap(stack->stack_a, i, i - 1);
    stack->stack_b[0] = stack->stack_a[0];
    i = -1;
    while (++i < stack->b_len - 1)
        index_swap(stack->stack_b, i, i + 1);
    stack->a_len++;
    stack->b_len--;
    ft_printf("pa\n");
}

void    pb(t_stack *stack)
{
    int i;

    i = stack->b_len + 1;
    while (--i > 0)
        index_swap(stack->stack_b, i, i - 1);
    stack->stack_b[0] = stack->stack_a[0];
    i = -1;
    while (++i < stack->a_len - 1)
        index_swap(stack->stack_a, i, i + 1);
    stack->a_len--;
    stack->b_len++;
    ft_printf("pb\n");
}
