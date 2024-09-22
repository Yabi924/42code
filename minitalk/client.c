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

int main(int argc, char **argv)
{
    // int i;

    // i = 0;
    if (argc == 2)
    {
        ft_printf("%s\n", argv[1]);
        ft_printf("hi\n");
    }
    else
    {
        ft_printf("please follow with: ./exe pid message.\n");
        return 0;
    }
    return 0;
}