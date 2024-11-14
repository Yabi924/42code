#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

typedef struct  s_philo
{
    char *str;
    int i;
    pthread_t *philo;
}   t_philo;

void    *handler(void *something)
{
    t_philo *a = (t_philo *)something;
    pthread_t tid = pthread_self();
    printf("%s%lu\n", a->str, (unsigned long int)tid);
    pthread_exit(NULL);
}

int main()
{
    int i = 0;
    t_philo s;
    s.str = strdup("tid:");
    while (i < 2)
    {
        s.i = i;
        pthread_create(&s.philo[i], NULL, &handler, &s);
        i++;
    }
    while (1)
    {
        if (pthread_join(s.philo[i], NULL))
            i--;
        if (i == 0)
            break;
    }
    return 0;
}