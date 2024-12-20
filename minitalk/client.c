/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:11:35 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/09 18:34:12 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_var(int s_pid, char *send)
{
	static int	bit = 7;
	static char	*str;
	static int	pid = 0;

	if (pid == 0)
		pid = s_pid;
	if (send)
		str = send;
	if (*str)
	{
		if (((unsigned char)*str >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		if (bit < 0)
		{
			bit = 7;
			str++;
		}
	}
	if (!(*str))
		exit(0);
}

void	sig_res(int signal)
{
	if (signal == SIGUSR1)
		get_var(0, NULL);
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, &sig_res);
	if (argc == 3)
		get_var(ft_atoi(argv[1]), argv[2]);
	else
	{
		ft_printf("please follow with: ./client <pid> <message>.\n");
		return (0);
	}
	while (1)
		pause();
	return (0);
}
