/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:13:41 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/30 20:28:55 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_overint(const char *str, int *mark)
{
	int		i;
	int		sign;
	long	save;

	i = 0;
	sign = 1;
	save = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		save = save * 10 + (str[i] - '0');
		if ((save * sign) > 2147483647 || (save * sign) < -2147483648)
			*mark = 1;
		i++;
	}
	return (save * sign);
}

void	index_swap(int *n, int i1, int i2)
{
	int	temp;

	temp = n[i1];
	n[i1] = n[i2];
	n[i2] = temp;
}

void	bb_sort(int *arr, int len)
{
	int	i;
	int	j;

	j = 0;
	if (!arr)
		return ;
	while (j < len - 1)
	{
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
				index_swap(arr, i, i + 1);
			i++;
		}
		j++;
	}
}

void	indexing(t_stack *stack)
{
	int	*temp;
	int	*copy;
	int	i;
	int	j;

	temp = copy_stack(stack->stack_a, stack->a_len);
	bb_sort(temp, stack->a_len);
	copy = (int *)malloc(sizeof(int) * stack->stack_len);
	if (!copy)
		error(stack, NULL, 0);
	j = 0;
	while (j < stack->a_len)
	{
		i = -1;
		while (++i < stack->a_len)
		{
			if (temp[j] == stack->stack_a[i])
			{
				copy[i] = j++;
				break ;
			}
		}
	}
	free(temp);
	copy_to_a_after_free(stack, copy);
}
