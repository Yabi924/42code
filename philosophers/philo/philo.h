/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:10:11 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/11/19 19:11:21 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_philo
{
    int philo_len;
    int time_to_dead;
    int sleep_time;
    int eat_time;
    int max_eat;
    int philo_code;
    pthread_mutex_t lock;
    pthread_mutex_t *fork;
    int is_dead;
}   t_philo;

//philo
void    *philo_live(void *adata);

//utils
int     ft_atoi(const char *str);
int     ft_strlen(char *str);
void    ft_wr(char *str);

#endif