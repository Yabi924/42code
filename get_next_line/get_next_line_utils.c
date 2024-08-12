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

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

int	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (TRUE);
		s++;
	}
	return (FALSE);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	ttllen;
	char	*str;

	if (!s1)
		s1 = ft_strdup(s1);
	if (!s1 || !s2)
		return (NULL);
	ttllen = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(ttllen + 1);
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return ((char *)str);
}

static int	count(const char *s, unsigned int start, size_t len)
{
	int	actual_len;

	if (!s)
		return (0);
	if (ft_strlen(s) - start < len)
		actual_len = ft_strlen(s) - start;
	else
		actual_len = len;
	return (actual_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		actual_len;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	actual_len = count(s, start, len);
	str = (char *)malloc(sizeof(char) * (actual_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, actual_len + 1);
	return (str);
}