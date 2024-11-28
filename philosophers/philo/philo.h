/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:10:11 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/11/28 01:41:07 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;

	int				philo_code;
	int				is_dead;
	int				eat_max;
	long long		start_time;
	long long		*last_eat;
	pthread_mutex_t	lock;
	pthread_mutex_t	*fork;
}	t_philo;

int			ft_atoi(const char *str);
void		error_messege(char *s);
void		*philo_life(void *philo_data);
void		messege(t_philo *data, char *tpye, int philo_code);
void		ft_usleep(int time);
long long	get_time(void);
void		one_philo(t_philo *data);
void		free_data(t_philo *data);

#endif
