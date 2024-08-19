/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:34:17 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/08/09 18:34:31 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s)
{
	if (!s)
		return (FALSE);
	while (*s)
	{
		if (*s == '\n')
			return (TRUE);
		s++;
	}
	return (FALSE);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	ttllen;
	char	*str;
	char	*ptr;

	ttllen = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(ttllen + 1);
	if (!str)
		return (NULL);
	ptr = str;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count > 0 && count > UINT_MAX / size)
		return (NULL);
	mem = (void *)malloc(count * size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, count * size);
	return (mem);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*i;

	i = b;
	while (len != 0)
	{
		*i = (unsigned char)c;
		len--;
		i++;
	}
	return (b);
}
