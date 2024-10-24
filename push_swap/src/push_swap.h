#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct  s_stack
{
    int *stack_a;
    int *stack_b;
    int a_len;
    int b_len;
    int stack_len;

    int mark;
}   t_stack;

void    push_swap(t_stack *stack);

void    init_v(t_stack *stack, char *s);
void    init_arr(t_stack *stack, char **argv);
int     check_double(t_stack *stack, int f);
int     check_arr_number_ii(char **s);
void    check_arr_number(t_stack *stack, char **s);

int     ft_atoi_overint(const char *str, int *mark);
void    error(t_stack *stack,int f);
void    free_arr(char **arr);
void    error_free_arr(t_stack *stack, char **arr);

//swap
void    sa(t_stack *stack);
void    sb(t_stack *stack);
void    ss(t_stack *stack);
void    pb(t_stack *stack);
void    pa(t_stack *stack);
void    pb(t_stack *stack);

//test
void    test(t_stack *stack);
void    print_a(t_stack *stack);
void    print_b(t_stack *stack);

#endif