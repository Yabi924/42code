/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:13:32 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/30 20:42:33 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hc_3(t_stack *stack)
{
	if (stack->stack_a[0] == 0 && stack->stack_a[1] == 2 && \
			stack->stack_a[2] == 1)
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->stack_a[0] == 2 && stack->stack_a[1] == 0 && \
			stack->stack_a[2] == 1)
	{
		rra(stack);
		rra(stack);
	}
	else if (stack->stack_a[0] == 2 && stack->stack_a[1] == 1 && \
			stack->stack_a[2] == 0)
	{
		sa(stack);
		rra(stack);
	}
	else if (stack->stack_a[0] == 1 && stack->stack_a[1] == 0 && \
			stack->stack_a[2] == 2)
		sa(stack);
	else if (stack->stack_a[0] == 1 && stack->stack_a[1] == 2 && \
			stack->stack_a[2] == 0)
		rra(stack);
}

void	hc_4(t_stack *stack)
{
	while (stack->stack_a[0] != 0)
		ra(stack);
	pb(stack);
	indexing(stack);
	hc_3(stack);
	pa(stack);
}

void	hc_5(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (stack->stack_a[0] == 0 || stack->stack_a[0] == 1)
		{
			pb(stack);
			i++;
		}
		else
			ra(stack);
	}
	if (stack->stack_b[0] < stack->stack_b[1])
		sb(stack);
	indexing(stack);
	hc_3(stack);
	pa(stack);
	pa(stack);
}

void	hardcode(t_stack *stack)
{
	if (stack->stack_len == 2)
		sa(stack);
	else if (stack->stack_len == 3)
		hc_3(stack);
	else if (stack->stack_len == 4)
		hc_4(stack);
	else if (stack->stack_len == 5)
		hc_5(stack);
}
