#include "push_swap.h"

int	ft_atoi_overint(const char *str, int *mark)
{
	int	i;
	int	sign;
	long	save;

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
        if (save > INT_MAX || save < INT_MIN)
            *mark = 1;
		i++;
	}
	return (save * sign);
}

void    index_swap(int *n, int i1, int i2)
{
    int temp;

    temp = n[i1];
    n[i1] = n[i2];
    n[i2] = temp;
}

int	*copy_stack(int *target, int len)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = target[i];
		i++;
	}
	return (arr);
}
