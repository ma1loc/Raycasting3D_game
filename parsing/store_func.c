/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:03:24 by ytabia            #+#    #+#             */
/*   Updated: 2025/07/30 17:54:14 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	store_and_validat_map(char *file, t_game *game)
{
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (skip_to_map_start(fd, game) == -1)
		return (close(fd), -1);
	preprocess_map_file(file, game);
	map = allocate_map(game);
	if (!map)
		return (close(fd), 1);
	if (read_map_lines(fd, map, game) == -1)
		return (close(fd), 1);
	game->map = map;
	close(fd);
	return (0);
}

int	skip_to_map_start(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while (i < game->map_start_line)
	{
		line = get_next_line(fd);
		if (!line)
			return (-1);
		free(line);
		i++;
	}
	return (0);
}

int	preprocess_map_file(char *file, t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (i < game->map_start_line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	game->map_lines = get_map_lines(fd);
	close(fd);
	return (0);
}

char	**allocate_map(t_game *game)
{
	char	**map;
	int		j;

	map = malloc(sizeof(char *) * (game->map_lines + 1));
	if (!map)
		return (NULL);
	j = 0;
	while (j <= game->map_lines)
	{
		map[j] = NULL;
		j++;
	}
	return (map);
}

int	read_map_lines(int fd, char **map, t_game *game)
{
	int		map_index;

	map_index = map_loop(fd, map, game);
	if (map_index == -1)
		return (-1);
	map[map_index] = NULL;
	return (0);
}
