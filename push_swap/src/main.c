#include "push_swap.h"

void    init_stack(t_stack *stack, int len)
{
    stack->stack_a = NULL;
    stack->stack_b = NULL;
    stack->stack_len = len;
    stack->a_len = 0;
    stack->b_len = 0;
}

int main(int argc, char **argv)
{
    t_stack stack;

    if (argc == 1)
        return (0);
    init_stack(&stack, argc - 1);
    check(&stack, argc, argv);
    push_swap(&stack);
    return (0);
}
