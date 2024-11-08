/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:13:48 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/30 20:34:00 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_number(t_stack *stack, char **s, int flag)
{
	int	i;
	int	j;
	int	mark;

	i = 0;
	j = 1;
	mark = 0;
	if (flag)
		j--;
	while (i < stack->stack_len)
	{
		stack->stack_a[i++] = ft_atoi_overint(s[j++], &mark);
		if (mark)
			return (0);
	}
	stack->a_len = i;
	return (1);
}

void	init_str(t_stack *stack, char *s)
{
	char	**arr_num;

	if (!s[0])
		error(stack, NULL, 1);
	arr_num = ft_split(s, ' ');
	stack->stack_len = check_arr_number(arr_num, 1);
	if (!stack->stack_len)
		error(stack, arr_num, 1);
	stack->stack_a = (int *)malloc(sizeof(int) * (stack->stack_len));
	stack->stack_b = (int *)malloc(sizeof(int) * (stack->stack_len));
	if (!stack->stack_a || !stack->stack_b)
		error(stack, NULL, 0);
	if (!get_number(stack, arr_num, 1))
		error(stack, arr_num, 1);
	if (arr_num)
		free_arr(arr_num);
}

void	init_arr(t_stack *stack, char **argv)
{
	stack->stack_a = (int *)malloc(sizeof(int) * (stack->stack_len));
	stack->stack_b = (int *)malloc(sizeof(int) * (stack->stack_len));
	if (!stack->stack_a || !stack->stack_b)
		error(stack, NULL, 0);
	if (!get_number(stack, argv, 0))
		error(stack, NULL, 1);
}

void	check(t_stack *stack, int argc, char **argv)
{
	if (argc == 2)
		init_str(stack, argv[1]);
	else
	{
		if (!check_arr_number(argv, 0))
			error(stack, NULL, 1);
		init_arr(stack, argv);
	}
	if (stack->stack_len == 1)
	{
		free_stack(stack);
		exit(0);
	}
	if (check_double(stack))
		error(stack, NULL, 1);
}
