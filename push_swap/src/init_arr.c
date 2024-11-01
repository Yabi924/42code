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

int	count_arr(t_stack *stack, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] == '\0' || ft_isdigit(str[i - 1]))
				error(stack);
			i++;
		}
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				i++;
			len++;
		}
		else if (str[i])
			error(stack);
	}
	return (len);
}

int	number_to_stack_a(t_stack *stack, char **s, int f)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (f)
		j--;
	while (i < stack->stack_len)
	{
		stack->stack_a[i++] = ft_atoi_overint(s[j++], &stack->mark);
		if (stack->mark)
			return (0);
	}
	stack->a_len = i;
	return (1);
}

void	init_str(t_stack *stack, char *s)
{
	char	**arr_num;

	if (!s[0])
		error(stack);
	stack->stack_len = count_arr(stack, s);
	stack->stack_a = (int *)malloc(sizeof(int) * (stack->stack_len));
	stack->stack_b = (int *)malloc(sizeof(int) * (stack->stack_len));
	if (!stack->stack_a || !stack->stack_b)
		error(stack);
	arr_num = ft_split(s, ' ');
	if (check_arr_number(arr_num))
		error_free_arr(stack, arr_num);
	if (!number_to_stack_a(stack, arr_num, 1))
		error_free_arr(stack, arr_num);
	if (arr_num)
		free_arr(arr_num);
	if (stack->stack_len == 1)
		error2(stack);
}

void	init_arr(t_stack *stack, char **argv)
{
	stack->stack_a = (int *)malloc(sizeof(int) * (stack->stack_len));
	stack->stack_b = (int *)malloc(sizeof(int) * (stack->stack_len));
	if (!stack->stack_a || !stack->stack_b)
		error(stack);
	number_to_stack_a(stack, argv, 0);
}

void	check(t_stack *stack, int argc, char **argv)
{
	if (argc == 2)
		init_str(stack, argv[1]);
	else
	{
		if (check_arr_number(argv))
			error(stack);
		init_arr(stack, argv);
	}
	if (stack->mark)
		error(stack);
	if (stack->stack_len == 1)
		error2(stack);
	if (check_double(stack))
		error(stack);
}
