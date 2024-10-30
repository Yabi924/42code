/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:13:59 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/30 18:14:01 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_bit(int n, int b)
{
    if ((n >> b) & 1)
        return (1);
    return (0);
}

void    radix_sort(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    while (!is_sorted(stack))
    {
        j = 0;
        while (j < stack->stack_len)
        {
            if (check_bit(stack->stack_a[0], i))
                ra(stack);
            else
                pb(stack);
            j++;
        }
        while (stack->b_len != 0)
            pa(stack);
        i++;
    }
}

void    push_swap(t_stack *stack)
{
    indexing(stack);
    if (stack->stack_len <= 5)
        hardcode(stack);
    else
        radix_sort(stack);
    // ft_printf("is sort:%d\n", is_sorted(stack));
}
