#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
char	*ft_loop_read(int fd, char *left_over);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_seperate_line(char *left_over);
char	*ft_free_left_over(char *left_over);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_buffjoin(char *left_over, char *bufferstr);

#endif
