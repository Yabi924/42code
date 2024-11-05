#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

typedef struct  s_philo
{
    int philo_len;
    int time_to_dead;
    int sleep_time;
    int eat_time;
    int philo_code;
    pthread_t *frok;
    pthread_t *last_eat;
    char    *str;
}   t_philo;

int     ft_atoi(const char *str);
int     ft_strlen(char *str);
void    ft_wr(char *str);

#endif