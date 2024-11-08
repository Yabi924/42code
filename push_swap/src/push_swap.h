/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:14:53 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/11/04 11:39:56 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	a_len;
	int	b_len;
	int	stack_len;
}	t_stack;

//main function
void	push_swap(t_stack *stack);
void	hardcode(t_stack *stack);

//init stack
void	init_str(t_stack *stack, char *s);
void	init_arr(t_stack *stack, char **argv);

//checking
void	check(t_stack *stack, int argc, char **argv);
int		check_double(t_stack *stack);
int		is_sorted(t_stack *stack);
//flag 1 = ./push_swap "1 2 3"
int		check_arr_number(char **s, int flag);

//main helper function
void	indexing(t_stack *stack);
void	index_swap(int *n, int i1, int i2);
void	bb_sort(int *arr, int len);
int		ft_atoi_overint(const char *str, int *mark);
//flag 1 = ./push_swap "1 2 3"
int		get_number(t_stack *stack, char **s, int flag);

//helper function
int		*copy_stack(int *target, int len);
void	copy_to_a_after_free(t_stack *stack, int *copy);
void	free_arr(char **arr);
void	free_stack(t_stack *stack);

//swap
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

//error 
//flag 1 = print Error
void	error(t_stack *stack, char **arr, int flag);

#endif
