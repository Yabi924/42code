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

void    ft_01(char *c_pid, char  *send)
{
    int pid;

    pid = ft_atoi(c_pid);
    ft_printf("pid:%d\n", pid);
    ft_printf("%s\n", send);
}    



int main(int argc, char **argv)
{
    // int i;

    // i = 0;
    if (argc == 3)
    {
        ft_01(argv[1], argv[2]);
    }
    else
    {
        ft_printf("please follow with: ./exe pid message.\n");
        return 0;
    }
    return 0;
}