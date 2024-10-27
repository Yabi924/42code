#include "push_swap.h"

int check_double(t_stack *stack)
{
    int i;
    int j;
    int db;

    i = 0;
    while (i < stack->stack_len)
    {
        db = 0;
        j = 0;
        while (j < stack->stack_len)
        {
            if (stack->stack_a[i] == stack->stack_a[j])
                db++;
            j++;
        }
        if (db > 1)
            return (1);
        i++;
    }
    return (0);
}

int check_arr_number(char **s)
{
    int i;
    int j;

    j = 1;
    while (s[j])
    {
        i = 0;
        while (s[j][i])
        {
            if (s[j][i] != '-' && s[j][i] != '+' && \
                !ft_isdigit(s[j][i]))
                return (1);
            if ((s[j][i] == '-' || s[j][i] == '+') && \
                !ft_isdigit(s[j][i + 1]))
                return (1);
            i++;
        }
        j++;
    }
    return (0);
}

int is_sorted(t_stack *stack)
{
    int i;
    i = 0;
    while (i < stack->a_len - 1)
    {
        if (stack->stack_a[i] > stack->stack_a[i + 1])
            return (0);
        i++;
    }
    if (stack->a_len != stack->stack_len || stack->b_len != 0)
        return (0);
    return (1);
}