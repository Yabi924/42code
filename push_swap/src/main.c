#include "push_swap.h"

void    init_stack(t_stack *stack, int len)
{
    stack->stack_a = NULL;
    stack->stack_b = NULL;
    stack->stack_len = len;
    stack->a_len = 0;
    stack->b_len = 0;
    stack->mark = 0;
}

int main(int argc, char **argv)
{
    t_stack stack;

    init_stack(&stack, argc - 1);
    if (argc == 2)
        init_v(&stack, argv[1]);
    else if (argc > 3)
    {
        check_arr_number(&stack, argv);
        init_arr(&stack, argv);
    }
    return (0);
}
