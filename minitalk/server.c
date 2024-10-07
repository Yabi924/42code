/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:11:16 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/09/22 13:11:18 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	res_word(int signal)
{
	static char	word = 0;
	static int	i = 0;

	// ft_printf("\nsignal:%d\n", signal);

	if (signal == SIGUSR1)
		word = (word << 1) | 1;
	else if (signal == SIGUSR2)
		word = (word << 1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", word);
		word = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_flags = 0;
	action.sa_handler = res_word;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("process pid:%d\n", getpid());
	while (1)
		pause();
	return (0);
}
