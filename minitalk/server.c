/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:11:16 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/09/22 13:11:18 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// char    res_word(int signal)
// {
//     static char word;
//     static int i;
//     char c;

//     word = 0;
//     i = 8;
//     if (signal == SIGUSR1)
//     {
//         word >> i = 1;
//         i--;
//     }
//     else
//     {
//         word >> i = 0;
//         i--;
//     }
//     if (i == 0)
//     {
//         c = word;
//         word = '\0';
//         return (c);
//     }
// }

void    res_str(int signal)
{
    while (1)
    {
        // ft_printf("%c", res_word(signal));
        ft_printf("%d", signal);
        pause();
    }
}

int main()
{
    struct sigaction action;
    action.sa_handler = res_str;

    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    
    ft_printf("process pid:%s\n", getpid());


    return (0);
}