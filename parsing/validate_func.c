/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:05:54 by ytabia            #+#    #+#             */
/*   Updated: 2025/08/12 23:32:08 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate_map_char(t_game *game)
{
	int	i;
	int	j;
	int	row_len;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		row_len = ft_strlen(game->map[i]);
		while (j < row_len)
		{
			if (!is_valid_char(game->map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\n');
}

int	is_space_valid(char **map, int i, int j, int map_height)
{
	int	row_len;
	int	prev_row_len;
	int	next_row_len;

	row_len = ft_strlen(map[i]);
	if (j > 0 && is_whitespace(map[i][j - 1]))
		return (0);
	if (j + 1 < row_len && is_whitespace(map[i][j + 1]))
		return (0);
	if (i > 0)
	{
		prev_row_len = ft_strlen(map[i - 1]);
		if (j >= prev_row_len || is_whitespace(map[i - 1][j]))
			return (0);
	}
	if (i + 1 < map_height && map[i + 1])
	{
		next_row_len = ft_strlen(map[i + 1]);
		if (j >= next_row_len || is_whitespace(map[i + 1][j]))
			return (0);
	}
	return (1);
}

int	validate_spaces(t_game *game)
{
	int	i;
	int	j;
	int	row_len;

	game->map_height = get_map_height(game->map);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		row_len = ft_strlen(game->map[i]);
		while (j < row_len)
		{
			if (game->map[i][j] == '0' || game->map[i][j] == 'N'
				|| game->map[i][j] == 'S' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'W')
			{
				if (!is_space_valid(game->map, i, j, game->map_height))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_textures(t_config *config)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (config->ids[i].id[0] == '\0')
		{
			err("Error:\nmissing or invalid texture\n");
			return (1);
		}
		i++;
	}
	if (!validate_rgb_is_set(config->ceiling_rgb))
	{
		err("Error:\nmissing or invalid ceiling\n");
		return (1);
	}
	if (!validate_rgb_is_set(config->floor_rgb))
	{
		err("Error:\nmissing or invalid floor\n");
		return (1);
	}
	return (0);
}
