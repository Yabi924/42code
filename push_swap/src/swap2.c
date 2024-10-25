#include "push_swap.h"

//first to last
void    ra(t_stack *stack)
{
    int temp;
    int i;

    temp = stack->stack_a[0];
    i = -1;
    while (++i < stack->a_len - 1)
        index_swap(stack->stack_a, i, i + 1);
    stack->stack_a[stack->a_len - 1] = temp;
    ft_printf("ra\n");
}

void    rb(t_stack *stack)
{
    int temp;
    int i;

    temp = stack->stack_b[0];
    i = -1;
    while (++i < stack->b_len - 1)
        index_swap(stack->stack_b, i, i + 1);
    stack->stack_b[stack->b_len - 1] = temp;
    ft_printf("ra\n");
}

//last to first
void    rra(t_stack *stack)
{
    int temp;
    int i;

    temp = stack->stack_a[stack->a_len - 1];
    i = stack->a_len;
    while (--i > 0)
        index_swap(stack->stack_a, i, i - 1);
    stack->stack_a[0] = temp;
    ft_printf("rra\n");
}

void    rrb(t_stack *stack)
{
    int temp;
    int i;

    temp = stack->stack_b[stack->b_len - 1];
    i = stack->b_len;
    while (--i > 0)
        index_swap(stack->stack_b, i, i - 1);
    stack->stack_b[0] = temp;
    ft_printf("rrb\n");
}
