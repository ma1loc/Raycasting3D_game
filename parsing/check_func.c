/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:46:01 by ytabia            #+#    #+#             */
/*   Updated: 2025/08/04 16:47:34 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map_extension(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i >= 1)
	{
		i--;
		if (str[i] == 'b' && str[i - 1] == 'u' && str[i - 2] == 'c')
			return (0);
		return (1);
	}
	return (0);
}

int	check_row_walls(char *row)
{
	int	j;
	int	row_len;

	if (!row)
		return (1);
	row_len = ft_strlen(row);
	if (row_len == 0)
		return (1);
	j = 0;
	while (j < row_len)
	{
		if (row[j] == ' ' || row[j] == '\n')
		{
			j++;
			continue ;
		}
		if (row[j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_middle_row_walls(char *row)
{
	int	j;
	int	row_len;

	if (!row)
		return (1);
	row_len = ft_strlen(row);
	if (row_len == 0)
		return (1);
	j = 0;
	while (j < row_len && (row[j] == ' ' || row[j] == '\n'))
		j++;
	if (j >= row_len || row[j] != '1')
		return (1);
	j = row_len - 1;
	while (j >= 0 && (row[j] == ' ' || row[j] == '\n'))
		j--;
	if (j < 0 || row[j] != '1')
		return (1);
	return (0);
}

int	check_map_wall(t_game *game)
{
	int	i;
	int	map_height;

	if (!game || !game->map || !game->map[0])
		return (1);
	map_height = get_map_height(game->map);
	if (map_height < 3)
		return (1);
	if (check_row_walls(game->map[0]))
		return (1);
	i = 1;
	while (i < map_height - 1)
	{
		if (check_middle_row_walls(game->map[i]))
			return (1);
		i++;
	}
	if (check_row_walls(game->map[map_height - 1]))
		return (1);
	return (0);
}

int	check_map_chars(t_game *game)
{
	int	player_count;

	if (!game->map || !game->map[0])
		return (1);
	if (validate_map_char(game))
		return (1);
	if (validate_spaces(game))
	{
		return (1);
	}
	player_count = count_player(game->map);
	if (player_count != 1)
	{
		return (1);
	}
	get_player_position(game);
	return (0);
}
