/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:14:26 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/30 20:25:58 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_struct(t_stack *stack, int len)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->stack_len = len;
	stack->a_len = 0;
	stack->b_len = 0;
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	init_struct(&stack, argc - 1);
	check(&stack, argc, argv);
	if (!is_sorted(&stack))
		push_swap(&stack);
	free_stack(&stack);
	return (0);
}
