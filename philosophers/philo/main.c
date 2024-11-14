/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:39:10 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/11/15 01:53:30 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_data(t_philo *data, char **argv)
{
    data->philo_len = ft_atoi(argv[1]);
    data->time_to_dead = ft_atoi(argv[2]);
    data->sleep_time = ft_atoi(argv[3]);
    data->eat_time = ft_atoi(argv[4]);
    data->philo_code = 0;
}

int check_data(t_philo *data)
{
    if (data->philo_len < 1 || data->time_to_dead < 0 || 
        data->sleep_time < 0 || data->eat_time < 0)
        return (0);
    return (1);
}

void run_thread(t_philo *data)
{
    int i;
    pthread_t *philo;

    i = 0;
    while (i < data->philo_len)
    {
        data->philo_code = i;
        pthread_create(&philo[i], NULL, &philo_live, data);
    }
    while (i != 0)
    {
        if (data->is_dead == 1)
            pthread_join(philo[i--], NULL);
    }
}

int main(int argc, char **argv)
{
    t_philo philo_data;

    if (argc < 5)
    {
        printf("usage: ./philo with 4 argument\n");
        return (1);
    }
    init_data(&philo_data, argv);
    if (!check_data(&philo_data))
    {
        printf("data invalid\n");
        return (1);
    }
    run_thread(&philo_data);
    return (0);
}