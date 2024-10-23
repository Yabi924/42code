#include "push_swap.h"

void    init_arr(t_stack *stack, int len)
{
    stack->stack_a = 0;
    stack->stack_b = 0;
    stack->stack_len = len;
}

int main(int argc, char **argv)
{
    t_stack stack;

    init_arr(&stack, argc - 1);
    if (argc == 2)
        arr_handler(&stack, argv[1]);
    else if (argc > 3)
        v_handler(&stack, argv);
    return 0;
}
