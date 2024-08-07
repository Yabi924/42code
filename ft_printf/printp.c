/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:50:55 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/07/21 16:50:56 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count_phex(uintptr_t ptr)
{
    int len;

    len = 0;
    if (ptr == 0)
        len++;
    while (ptr)
    {
        ptr /= 16;
        len++;
    }
    return (len);
}

int printphex(uintptr_t ptr)
{
    char *hex;
    int len;

    len = count_phex(ptr);
    hex = "0123456789ABCDEF";
    if (ptr >= 16)
        printphex(ptr / 16);
    write (1, &hex[ptr % 16], 1);
    return (len);
}

int printp(void *ptr)
{
    int len;
    uintptr_t p;

    // if (!ptr)
    // {
    //     write(1, "0x0", 3);
    //     return (4);
    // }
    len = 2;
    p = (uintptr_t)ptr;
    write (1, "0x", 2);
    len += printphex(p);
    return (len);
}
