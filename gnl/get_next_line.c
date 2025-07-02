#include "../srcs/cub3D.h"

static char	*ft_read_save(int fd, char *save)
{
	int		read_bytes;
	char	*buff;
	char	*tmp;

	buff = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buff), free(save), NULL);
		if (read_bytes == 0)
			break ;
		buff[read_bytes] = '\0';
		tmp = save;
		save = ft_strjoin(save, buff);
		free(tmp);
	}
	if (read_bytes == 0 && (!save || *save == '\0'))
		return (free(buff), free(save), NULL);
	free(buff);
	return (save);
}

static char	*ft_get_the_line(char *save)
{
	int		i;
	char	*s;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_update_save(char *save)
{
	char	*s;
	int		i;
	int		j;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*line;

	save = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	save = ft_read_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_the_line(save);
	save = ft_update_save(save);
	free(save);
	return (line);
}