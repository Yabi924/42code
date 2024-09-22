/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:11:35 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/09/22 13:11:37 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_asc_signal(int pid, char c)
{
    int i;

    i = 7;
    while (i != 0)
    {
        
    }
    ft_printf("char:%c\n", c);
}

void    get_var(char *c_pid, char  *send)
{
    int pid;
    int i;

    pid = ft_atoi(c_pid);
    i = 0;
    while (send[i])
        send_asc_signal(pid, send[i++]);
}



int main(int argc, char **argv)
{
    if (argc == 3)
    {
        get_var(argv[1], argv[2]);
    }
    else
    {
        ft_printf("please follow with: ./exe pid message.\n");
        return 0;
    }
    return 0;
}