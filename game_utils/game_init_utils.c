/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:42:51 by yanflous          #+#    #+#             */
/*   Updated: 2025/07/28 13:43:40 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	normalize_angle(double angle)
{
	double	new_angle;

	new_angle = fmod(angle, 2 * M_PI);
	if (new_angle < 0)
		new_angle += 2 * M_PI;
	return (new_angle);
}

int	hex_into_color(t_game *game, bool floor)
{
	int	r;
	int	g;
	int	b;

	if (floor)
	{
		r = game->config->floor_rgb[0];
		g = game->config->floor_rgb[1];
		b = game->config->floor_rgb[2];
	}
	else
	{
		r = game->config->ceiling_rgb[0];
		g = game->config->ceiling_rgb[1];
		b = game->config->ceiling_rgb[2];
	}
	return ((r << 16) | (g << 8) | b);
}

void	init_floor_ceiling_rgb(t_game *game)
{
	game->window.floor_color = hex_into_color(game, true);
	game->window.ceiling_color = hex_into_color(game, false);
}
