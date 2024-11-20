/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:07:36 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/11/19 19:22:00 by yyan-bin         ###   ########.fr       */
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
    philo = malloc(sizeof(pthread_t) * data->philo_len);
    pthread_mutex_init(&data->lock, NULL);
    while (i < data->philo_len)
    {
        data->philo_code = i;
        pthread_create(&philo[i++], NULL, &philo_live, data);
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

    if (argc != 5 && argc != 6)
    {
        printf("usage: ./philo with 4 argument\n");
        printf("optional: [number_of_times_each_philosopher_must_eat]\n");
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