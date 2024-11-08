/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:36:43 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/11/04 11:38:19 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_stack(int *target, int len)
{
	int	i;
	int	*arr;

	i = -1;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (++i < len)
		arr[i] = target[i];
	return (arr);
}

void	copy_to_a_after_free(t_stack *stack, int *copy)
{
	int	i;

	i = -1;
	while (++i < stack->a_len)
		stack->stack_a[i] = copy[i];
	free(copy);
}

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

void	free_stack(t_stack *stack)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
}

void	error(t_stack *stack, char **arr, int flag)
{
	if (arr)
		free_arr(arr);
	free_stack(stack);
	if (flag == 1)
		write(2, "Error\n", 6);
	exit(1);
}
