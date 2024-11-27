/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:53:50 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/11/28 00:58:20 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_philo *data, char **argv)
{
	int	i;

	i = 0;
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->start_time = get_time();
	data->is_dead = 0;
	data->eat_max = 0;
	data->last_eat = (long long *)malloc(sizeof(long long) * \
		data->number_of_philo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
	pthread_mutex_init(&(data->lock), NULL);
	while (i < data->number_of_philo)
	{
		data->last_eat[i] = 0;
		pthread_mutex_init(&(data->fork[i++]), NULL);
	}
}

int check_data(t_philo *data)
{
    if (data->number_of_philo < 1 || data->number_of_philo > 200 || \
        data->time_to_die < 60 || data->time_to_eat < 60 || \
        data->time_to_sleep < 60)
        return (1);
    return (0);
}

void    check_dead(t_philo *data)
{
    int i;
    int f;

    f = 1;
    while (f)
    {
        i = -1;
        while (++i < data->number_of_philo && f)
        {
            pthread_mutex_lock(&data->lock);
            if (get_time() - data->last_eat[i] > data->time_to_die)
            {
                f = 0;
                data->is_dead = 1;
                printf("%lld %d is dead\n", get_time() - data->start_time, i + 1);
            }
            else if (data->eat_max == 1 && data->must_eat > 0)
                f = 0;
            pthread_mutex_unlock(&data->lock);
        }
        usleep(1000);
    }
}

void    create_thread(t_philo *data)
{
    pthread_t *philo;
    int i;

    i = 0;
    philo = malloc(sizeof(pthread_t) * data->number_of_philo);
    while (i < data->number_of_philo)
    {
        pthread_mutex_lock(&data->lock);
        data->philo_code = i;
        data->last_eat[i] = data->start_time;
        pthread_mutex_unlock(&data->lock);
        pthread_create(&philo[i++], NULL, &philo_life, (void *)data);
        usleep(100);
    }
    check_dead(data);
    i = 0;
    while (i < data->number_of_philo)
        pthread_join(philo[i++], NULL);
}

int main(int argc, char **argv)
{
    t_philo data;

    if (argc != 5 && argc != 6)
    {
        error_messege("wrong input\n");
        return (1);
    }
    init_data(&data, argv);
    if (check_data(&data))
    {
        error_messege("invalid argument\n");
        return (1);
    }
    create_thread(&data);
    return (0);
}
