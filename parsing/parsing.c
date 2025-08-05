/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:58:04 by ytabia            #+#    #+#             */
/*   Updated: 2025/08/05 20:04:49 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_texture_index(const char *id)
{
	if (ft_strcmp(id, "NO") == 0)
		return (0);
	if (ft_strcmp(id, "SO") == 0)
		return (1);
	if (ft_strcmp(id, "WE") == 0)
		return (2);
	if (ft_strcmp(id, "EA") == 0)
		return (3);
	return (-1);
}

int	pars_textures(char *line, t_config *config, const char *id)
{
	int		index;
	int		fd;
	char	*extension;

	index = get_texture_index(id);
	if (index == -1)
		return (1);
	if (check_dub_texture_id(config, index))
		return (1);
	ft_strncpy(config->ids[index].id, id, 2);
	config->ids[index].id[2] = '\0';
	while (*line == ' ' || *line == '\t')
		line++;
	config->ids[index].path = ft_strdup(line);
	if (!config->ids[index].path)
		return (1);
	extension = ft_strrchr(config->ids[index].path, '.');
	if (check_texture_extension(extension))
		return (1);
	fd = open(config->ids[index].path, O_RDONLY);
	if (check_texture_path(fd))
		return (1);
	return (close(fd), 0);
}

int	pars_rgb(char *line, int *rgb)
{
	int		i;
	char	**split;

	i = 0;
	if (count_comma(line) != 2)
		return (1);
	split = ft_split(line, ',');
	if (!split)
		return (1);
	while (split[i])
	{
		if (ft_isdigit_str(split[i]))
			return (free_split(split), 1);
		i++;
	}
	i = -1;
	while (++i < 3)
	{
		if (split[i] == NULL)
			return (free_split(split), 1);
		rgb[i] = ft_atoi(split[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (free_split(split), 1);
	}
	return (free_split(split), 0);
}

int	parsing(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		return (err("Error:\nnumber arguments not correct\n"), 1);
	if (check_map_extension(argv[1]))
		return (err("Error:\nmap extension not correct\n"), 1);
	if (read_map(argv[1], game))
		return (cleanup_game(game), 1);
	if (check_map_wall(game))
		return (err("Error:\nmap wall not closed\n"), cleanup_game(game), 1);
	if (check_map_chars(game))
		return (err("Error:\nmap characters not correct\n"), cleanup_game(game),
			1);
	return (0);
}
