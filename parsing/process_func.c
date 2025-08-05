/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:53:44 by ytabia            #+#    #+#             */
/*   Updated: 2025/08/05 19:55:49 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	process_line(int fd, t_game *game, t_counters *counters)
{
	char	*line;
	char	*s;
	int		result;

	s = get_next_line(fd);
	if (!s)
		return (-1);
	line = ft_strtrim(s, "\n\t ");
	free(s);
	if (line[0] == '\0')
	{
		free(line);
		game->map_start_line++;
		return (0);
	}
	result = process_config_line(line, game, counters);
	free(line);
	if (result == 1)
		return (1);
	if (result == 2)
		return (2);
	game->map_start_line++;
	return (0);
}

int	process_config_line(char *line, t_game *game, t_counters *counters)
{
	if (is_texture_line(line))
		return (process_texture_line(line, game));
	else if (!ft_strncmp(line, "F ", 2))
		return (handle_floor_color(line, game->config, &counters->floor_count));
	else if (!ft_strncmp(line, "C ", 2))
		return (handle_ceiling_color(line, game->config,
				&counters->ceiling_count));
	else if (ft_isalpha(line[0]))
	{
		err("Error:\nmissing or invalid texture\n");
		free(line);
		cleanup_game(game);
		exit(1);
	}
	else
		return (2);
	return (0);
}

int	process_texture_line(char *line, t_game *game)
{
	const char	*id;

	id = get_texture_id(line);
	if (id)
	{
		if (pars_textures(line + 2, game->config, id))
			return (1);
	}
	return (0);
}
