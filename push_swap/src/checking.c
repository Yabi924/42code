#include "push_swap.h"

int check_double(t_stack *stack, int f)
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
        if (db > 1 && f != 1)
            error(stack, 2);
        else if (db > 1 && f == 1)
            return (1);
        i++;
    }
    return (0);
}

void check_arr_number(t_stack *stack, char **s)
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
                error(stack, 1);
            if ((s[j][i] == '-' || s[j][i] == '+') &&
                !ft_isdigit(s[j][i + 1]))
                error(stack, 1);
            i++;
        }
        j++;
    }
}

int check_arr_number_ii(char **s)
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
            if ((s[j][i] == '-' || s[j][i] == '+') &&
                !ft_isdigit(s[j][i + 1]))
                return (1);
            i++;
        }
        j++;
    }
    return (0);
}
