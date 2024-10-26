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

}   t_stack;

//main
void    push_swap(t_stack *stack);
void    hardcode(t_stack *stack);

//checking
void    init_str(t_stack *stack, char *s);
void    init_arr(t_stack *stack, char **argv);
void    check(t_stack *stack, int argc, char **argv);
int     check_double(t_stack *stack);
int     check_arr_number(char **s);
int     is_shorted(t_stack *stack);

//helper function
void    index_swap(int *n, int i1, int i2);
int     ft_atoi_overint(const char *str, int *mark);
int     *copy_stack(int *target, int len);
void    indexing(t_stack *stack);

//error
void    error(t_stack *stack);
void    free_arr(char **arr);
void    error_free_arr(t_stack *stack, char **arr);

//swap
void    sa(t_stack *stack);
void    sb(t_stack *stack);
void    ss(t_stack *stack);
void    pb(t_stack *stack);
void    pa(t_stack *stack);
void    pb(t_stack *stack);
void    ra(t_stack *stack);
void    rb(t_stack *stack);
void    rr(t_stack *stack);
void    rra(t_stack *stack);
void    rrb(t_stack *stack);
void    rrr(t_stack *stack);

//test
void    test(t_stack *stack);
void    print_a(t_stack *stack);
void    print_b(t_stack *stack);
void    print_temp(int *n, int len);

#endif