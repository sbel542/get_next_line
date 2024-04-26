#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	totalsize;
	char	*ptr1;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (SIZE_MAX / nmemb < size)
		return (NULL);
	totalsize = nmemb * size;
	ptr1 = (char *)malloc(totalsize);
	if (ptr1 != NULL)
		ft_memset(ptr1, 0, totalsize);
	return (ptr1);
}

char	*ft_buffjoin(char *left_over, char *bufferstr)
{
	char	*new_left_over;

	if (!left_over)
	{
		left_over = (char *)ft_calloc(1, sizeof(char));
		left_over[0] = '\0';
	}
	if (!left_over || !bufferstr)
	{
		free(left_over);
		return (NULL);
	}
	new_left_over = ft_strjoin(left_over, bufferstr);
	free(left_over);
	return (new_left_over);
}

char	*ft_loop_read(int fd, char *left_over)
{
	char	*bufferstr;
	int		read_count;

	bufferstr = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!bufferstr)
		return (NULL);
	read_count = 1;
	while (ft_strchr(left_over, '\n') == NULL && read_count != 0)
	{
		read_count = read(fd, bufferstr, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(bufferstr);
			return (NULL);
		}
		bufferstr[read_count] = '\0';
		left_over = ft_buffjoin(left_over, bufferstr);
	}
	free(bufferstr);
	return (left_over);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*left_over;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_over = ft_loop_read(fd, left_over);
	if (!left_over)
	{
		free(left_over);
		return (NULL);
	}
	next_line = ft_seperate_line(left_over);
	if (!next_line && !left_over)
	{
		free(left_over);
		return (NULL);
	}
	left_over = ft_free_left_over(left_over);
	return (next_line);
}
