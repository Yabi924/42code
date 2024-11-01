/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin.student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:18:29 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/30 20:16:31 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

void	error(t_stack *stack)
{
	if (stack->stack_a)
	{
		free(stack->stack_a);
	}
	if (stack->stack_b)
	{
		free(stack->stack_b);
	}
	write(2, "Error\n", 6);
	exit(0);
}

void	error_free_arr(t_stack *stack, char **arr)
{
	free_arr(arr);
	error(stack);
}

void	error2(t_stack *stack)
{
	if (stack->stack_a)
	{
		free(stack->stack_a);
	}
	if (stack->stack_b)
	{
		free(stack->stack_b);
	}
	exit(0);
}

void	error2_free_arr(t_stack *stack, char **arr)
{
	free_arr(arr);
	error2(stack);
}