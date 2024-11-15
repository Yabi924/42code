/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:48:27 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/11/15 18:55:39 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philo_live(void *adata)
{
    t_philo *data;

    data = (t_philo *)adata;
    printf("%d,%d,%d,%d\n", data->philo_code, data->time_to_dead, data->sleep_time, data->eat_time);
    pthread_mutex_lock(&data->lock);
    data->is_dead = 1;
    pthread_mutex_unlock(&data->lock);
    pthread_exit(NULL);
}