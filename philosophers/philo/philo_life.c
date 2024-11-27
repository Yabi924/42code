/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:52:54 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/11/28 00:52:57 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_dead(t_philo *data, int eat_count)
{
    pthread_mutex_lock(&data->lock);
    if (data->is_dead == 1 || eat_count == data->must_eat)
    {
        data->eat_max = 1;
        pthread_mutex_unlock(&data->lock);
        return (1);
    }
    pthread_mutex_unlock(&data->lock);
    return (0);
}

void    eat(t_philo *data, int philo_code, int fork1, int fork2)
{
    if (data->is_dead || data->eat_max)
        return ;
    if (philo_code % 2 == 0)
    {
        pthread_mutex_lock(&data->fork[fork1]);
        messege(data, "has taken a fork", philo_code);
        pthread_mutex_lock(&data->fork[fork2]);
        messege(data, "has taken a fork", philo_code);
    }
    else
    {
        pthread_mutex_lock(&data->fork[fork2]);
        messege(data, "has taken a fork", philo_code);
        pthread_mutex_lock(&data->fork[fork1]);
        messege(data, "has taken a fork", philo_code);
    }
    messege(data, "is eating", philo_code);
    pthread_mutex_lock(&data->lock);
    data->last_eat[philo_code] = get_time();
    pthread_mutex_unlock(&data->lock);
    ft_usleep(data->time_to_eat);
    pthread_mutex_unlock(&data->fork[fork1]);
    pthread_mutex_unlock(&data->fork[fork2]);
}

void    *philo_life(void *philo_data)
{
    t_philo *data;
    int philo_code;
    int fork1;
    int fork2;
    int eat_count;

    data = (t_philo *)philo_data;
    philo_code = data->philo_code;
    fork1 = philo_code;
    fork2 = fork1 + 1;
    eat_count = 0;
    if (philo_code == data->number_of_philo - 1)
        fork2 = 0;
    while (!is_dead(data, eat_count))
    {
            eat(data, philo_code, fork1, fork2);
            eat_count++;
            messege(data, "is sleeping", philo_code);
            ft_usleep(data->time_to_sleep);       
            messege(data, "is thinking", philo_code);
    }
    return NULL;
}
