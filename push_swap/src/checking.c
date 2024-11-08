/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:14:05 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/30 20:24:51 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_stack *stack)
{
	int	i;
	int	j;
	int	db;

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

int	check_arr_number(char **s, int flag)
{
	int	i;
	int	j;

	j = 1;
	if (flag == 1)
		j--;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] != '-' && s[j][i] != '+' && \
					!ft_isdigit(s[j][i]))
				return (0);
			if ((s[j][i] == '-' || s[j][i] == '+') && \
					(!ft_isdigit(s[j][i + 1]) || ft_isdigit(s[j][i - 1])))
				return (0);
			i++;
		}
		j++;
	}
	return (j);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_len - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		i++;
	}
	if (stack->a_len != stack->stack_len || stack->b_len != 0)
		return (0);
	return (1);
}
