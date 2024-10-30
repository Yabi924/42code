/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:12:48 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/30 18:13:07 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap a top with a second
void    sa(t_stack *stack)
{
    if (stack->a_len == 0)
        return ;
    index_swap(stack->stack_a, 0, 1);
    ft_printf("sa\n");
}

//swap b top with b second
void    sb(t_stack *stack)
{
    if (stack->b_len == 0)
        return ;
    index_swap(stack->stack_b, 0, 1);
    ft_printf("sb\n");
}

//sa + sb
void    ss(t_stack *stack)
{
    if (stack->a_len == 0 || stack->b_len == 0)
        return ;
    index_swap(stack->stack_a, 0, 1);
    index_swap(stack->stack_b, 0, 1);
    ft_printf("ss\n");
}

//push b topto a top
void    pa(t_stack *stack)
{
    int i;

    if (stack->b_len == 0)
        return ;
    i = stack->a_len + 1;
    while (--i > 0)
        index_swap(stack->stack_a, i, i - 1);
    stack->stack_b[0] = stack->stack_a[0];
    i = -1;
    while (++i < stack->b_len - 1)
        index_swap(stack->stack_b, i, i + 1);
    stack->a_len++;
    stack->b_len--;
    ft_printf("pa\n");
}

//push a top to b top
void    pb(t_stack *stack)
{
    int i;

    if (stack->a_len == 0)
        return ;
    i = stack->b_len + 1;
    while (--i > 0)
        index_swap(stack->stack_b, i, i - 1);
    stack->stack_b[0] = stack->stack_a[0];
    i = -1;
    while (++i < stack->a_len - 1)
        index_swap(stack->stack_a, i, i + 1);
    stack->a_len--;
    stack->b_len++;
    ft_printf("pb\n");
}
