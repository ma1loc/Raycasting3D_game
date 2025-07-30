/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:50:50 by ytabia            #+#    #+#             */
/*   Updated: 2025/07/30 18:02:42 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_loop(int fd, char **map, t_game *game)
{
	char	*line;
	int		map_index;

	map_index = 0;
	while (map_index < game->map_lines)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			if (check_newline_inside_map(map_index, game, map) == -1)
				return (-1);
			continue ;
		}
		if (!check_white_spaces(line))
		{
			free(line);
			continue ;
		}
		map[map_index] = line;
		map_index++;
	}
	return (map_index);
}

int	check_newline_inside_map(int map_index, t_game *game, char **map)
{
	if (map_index < game->map_lines)
	{
		free_this_map(map, map_index);
		return (-1);
	}
	return (0);
}

int	check_white_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	get_map_lines(int fd)
{
	char	*line;
	int		map_lines;

	map_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_lines++;
		free(line);
	}
	return (map_lines);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}
