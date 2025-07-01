#include "get_next_line.h"

// char	*ft_strchr(const char *str, int search_str)
// {
// 	char	ch;
// 	int		i;

// 	if (!str)
// 		return (NULL);
// 	ch = (char)search_str;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ch)
// 			return ((char *)str + i);
// 		i++;
// 	}
// 	if (ch == '\0')
// 		return ((char *)str + i);
// 	return (NULL);
// }

// static void	cpy(char *dest, const char *src)
// {
// 	int	i;

// 	i = 0;
// 	while (src[i])
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	total_len;
// 	char	*ptr;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 		return (ft_strdup(s2));
// 	if (!s2)
// 		return (ft_strdup(s1));
// 	total_len = ft_strlen(s1) + ft_strlen(s2);
// 	ptr = malloc(sizeof(char) * (total_len + 1));
// 	if (!ptr)
// 		return (NULL);
// 	cpy(ptr, s1);
// 	cpy(ptr + ft_strlen(s1), s2);
// 	return (ptr);
// }

// char	*ft_strdup(const char *str)
// {
// 	size_t	i;
// 	size_t	len;
// 	char	*ptr;

// 	if (!str)
// 		return (NULL);
// 	len = ft_strlen(str);
// 	ptr = malloc(sizeof(char) * (len + 1));
// 	if (!ptr)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		ptr[i] = str[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }
