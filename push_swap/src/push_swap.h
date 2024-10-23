#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct  s_stack
{
    int *stack_a;
    int *stack_b;
    int stack_len;
}   t_stack;

void    arr_handler(t_stack *stack, char *s);
void    v_handler(t_stack *stack, char **argv);
void    error(int f);

void    sa(t_stack *stack);

int	ft_atoi_overint(const char *str, int *mark);

#endif