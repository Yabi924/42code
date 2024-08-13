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

int	ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	ttllen;
	char	*str;
	char	*ptr;
	int i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ttllen = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(ttllen + 1);
	if (!str)
		return (NULL);
	ptr = str;
	i = 0;
	while (s1[i])
		*ptr++ = s1[i++];
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	free(s1);
	return (str);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		s1[0] = '\0';
// 	}
// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (s1)
// 		while (s1[++i] != '\0')
// 			str[i] = s1[i];
// 	while (s2[j] != '\0')
// 		str[i++] = s2[j++];
// 	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	free(s1);
// 	return (str);
// }
