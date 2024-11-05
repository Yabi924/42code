#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	save;

	i = 0;
	sign = 1;
	save = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		save = save * 10 + (str[i] - '0');
		i++;
	}
	return (save * sign);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

void wr(char *str)
{
    int i = 0;

    if (!str)
        return ;
    while (str[i])
        write(1, &str[i++], 1);
}


