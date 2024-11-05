#include "philo.h"

void    init_data(t_philo *data, char **argv)
{
    data->philo_len = ft_atoi(argv[1]);
    data->time_to_dead = ft_atoi(argv[2]);
    data->eat_time = ft_atoi(argv[3]);
    data->sleep_time = ft_atoi(argv[4]);
    data->str = argv[0];
    data->philo_code = 0;
}

void    *handler(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    philo->str[0] = philo->philo_code + '0';
    printf("p:%d %s\n", philo->philo_code, philo->str);
    // pthread_exit(NULL);
    return NULL;
}

void    create(t_philo *data)
{
    pthread_t thread[3];

    int i = 0;
    while (i < 3)
    {
        data->philo_code = i;
        pthread_create(&thread[i++], NULL, &handler, &thread);
    }
    for (int j = 0; j < 3; j++) {
        pthread_join(thread[j], NULL);
    }
}

int main(int argc, char **argv)
{
    t_philo philo_data;

    if (argc == 1)
    {
        printf("program must follow by: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\n");
        return 0;
    }
    init_data(&philo_data, argv);
    create(&philo_data);
    // create_thread(&philo_data);
}