#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

char	*ft_strchr(char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == uc)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == uc)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		result[s1_len + j] = s2[j];
		j++;
	}
	result[s1_len + s2_len] = '\0';
	return (result);
}

char	*ft_seperate_line(char *left_over)
{
	int		i;
	char	*line;

	i = 0;
	if (!left_over[i])
		return (NULL);
	while (left_over[i] && left_over[i] != '\n')
		i++;
	line = (char *)ft_calloc((sizeof(char)), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (left_over[i] && left_over[i] != '\n')
	{
		line[i] = left_over[i];
		i++;
	}
	if (left_over[i] == '\n')
	{
		line[i] = left_over[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_free_left_over(char *left_over)
{
	char			*remaining;
	size_t			i;
	size_t			j;

	i = 0;
	while (left_over[i] && left_over[i] != '\n')
		i++;
	if (!left_over[i])
	{
		free(left_over);
		return (NULL);
	}
	remaining = (char *)ft_calloc((ft_strlen(left_over) - i + 1), sizeof(char));
	if (!remaining)
		return (NULL);
	i++;
	j = 0;
	while (left_over[i])
		remaining[j++] = left_over[i++];
	remaining[j] = '\0';
	free(left_over);
	return (remaining);
}
