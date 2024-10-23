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

void arr_handler(t_stack *stack, char *s)
{
    int arr_len;

    arr_len = count_arr(s);
    ft_printf("arr_len:%d\n", arr_len);
    if (arr_len && !(arr_len < 3))
    {
        stack->stack_a = 0;
    }
    else
        error(1);
}

int check(t_stack *stack)
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

void    v_handler(t_stack *stack, char **argv)
{
    int i;
    int j;
    int mark;

    i = 0;
    j = 1;
    mark = 0;
    stack->stack_a = (int *)malloc(sizeof(int) * (stack->stack_len));
    stack->stack_b = (int *)malloc(sizeof(int) * (stack->stack_len));
    if (!stack->stack_a || !stack->stack_b)
        error(2);
    while (i < stack->stack_len)
    {
        stack->stack_a[i++] = ft_atoi_overint(argv[j++], &mark);
        if (mark)
            error(3);
    }
    i = 0;
    while (i < stack->stack_len)
        ft_printf("%d\n", stack->stack_a[i++]);
    ft_printf("check:%d\n", check(stack));
}