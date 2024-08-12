
#include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	ttllen;
	char	*str;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
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

int main()
{
	char *sss = (char *)malloc(10);
	if (!sss)
		printf("NULL");
	sss = ft_strdup(sss);
	printf("%s\n", sss);
	char *s1 = (char *)malloc(10);
	s1 = "abf";
	sss = ft_strjoin(s1, "123");
	printf("%s\n", sss);
	
	if (!s1)
	{
		printf("NULL");
		printf("%s\n", s1);
	}
	return 0;
}