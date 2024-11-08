#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct  s_philo
{
    char *str;
    pthread_t s;
}   t_philo;

int main()
{
    int i = 0;
    int p = 0;

    pthread_t *philo;

    philo = (pthread_t *)malloc(sizeof(pthread_t) * 10);
    while (i != 10)
    {
        pthread_create(philo, NULL, )
    }
}