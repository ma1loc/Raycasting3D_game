#include "../srcs/cub3D.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (unsigned char)s1[i] - (unsigned char)s2[i];
}

char *ft_strncpy(char *dest, const char *src, int n)
{
	int i;

	i = 0;

	while(i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
	return(dest);
}
int is_texture_line(char *line)
{
    return (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3));
}
const char *get_texture_id(const char *line)
{
    if (ft_strncmp(line, "NO", 2) == 0)
        return "NO";
    if (ft_strncmp(line, "SO", 2) == 0)
        return "SO";
    if (ft_strncmp(line, "WE", 2) == 0)
        return "WE";
    if (ft_strncmp(line, "EA", 2) == 0)
        return "EA";
    return NULL;
}