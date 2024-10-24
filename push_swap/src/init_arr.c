#include "push_swap.h"

int count_arr(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i] == '-' || str[i] == '+')
        {
            if (str[i + 1] == '\0')
                return (0);
            i++;
        }
        if (ft_isdigit(str[i]))
        {
            while (ft_isdigit(str[i]))
                i++;
            len++;
        }
        else if (str[i])
            return (0);
    }
    return (len);
}

int number_to_stack_a(t_stack *stack, char **s, int f)
{
    int i;
    int j;

    i = 0;
    j = 1;
    if (f)
        j--;
    while (i < stack->stack_len)
    {
        stack->stack_a[i++] = ft_atoi_overint(s[j++], &stack->mark);
        if (stack->mark && f == 1)
            return (0);
        else if (stack->mark && f == 0)
            error(stack, 2);
    }
    return (1);
}

void init_v(t_stack *stack, char *s)
{
    char    **arr_num;

    stack->stack_len = count_arr(s);
    if (stack->stack_len == 0 && (stack->stack_len < 3))
        error(stack, 1);
    stack->stack_a = (int *)malloc(sizeof(int) * (stack->stack_len));
    stack->stack_b = (int *)malloc(sizeof(int) * (stack->stack_len));
    if (!stack->stack_a || !stack->stack_b)
        error(stack, 1);
    arr_num = ft_split(s, ' ');
    if (check_arr_number_ii(arr_num))
        error_free_arr(stack, arr_num);
    if (!number_to_stack_a(stack, arr_num, 1))
        error_free_arr(stack, arr_num);
    if (check_double(stack, 1))
        error_free_arr(stack, arr_num);
    else
        push_swap(stack);
    free_arr(arr_num);
}

void    init_arr(t_stack *stack, char **argv)
{
    int i;

    i = 0;
    stack->stack_a = (int *)malloc(sizeof(int) * (stack->stack_len));
    stack->stack_b = (int *)malloc(sizeof(int) * (stack->stack_len));
    if (!stack->stack_a || !stack->stack_b)
        error(stack, 1);
    if (number_to_stack_a(stack, argv, 0))
    {
        check_double(stack, 0);
        push_swap(stack);
    }
}
