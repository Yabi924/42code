/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:52:59 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/11/28 01:22:31 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	save;

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
		i++;
	}
	return (save * sign);
}

void	error_messege(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return ;
	while (s[i])
		write(1, &s[i++], 1);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	messege(t_philo *data, char *m, int philo_code)
{
	pthread_mutex_lock(&data->lock);
	if (data->is_dead || data->eat_max)
	{
		pthread_mutex_unlock(&data->lock);
		return ;
	}
	printf("%lld %d %s\n", get_time() - data->start_time, philo_code + 1, m);
	pthread_mutex_unlock(&data->lock);
}

void	ft_usleep(int time)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(500);
}
