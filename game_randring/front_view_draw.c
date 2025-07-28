/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_view_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:55:55 by yanflous          #+#    #+#             */
/*   Updated: 2025/07/28 13:31:15 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_ceiling(t_game *game, int row, int column, int ceiling)
{
	int	ceiling_color;

	ceiling_color = game->window.ceiling_color;
	while (column < ceiling)
	{
		my_mlx_pixel_put(game, row, column, ceiling_color);
		column++;
	}
}

void	draw_floor(t_game *game, int row, int column)
{
	int	floor_color;

	floor_color = game->window.floor_color;
	while (column < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(game, row, column, floor_color);
		column++;
	}
}

void	draw_column_line(t_game *game, int row)
{
	int	top;
	int	bottom;
	int	wall_height;

	wall_height = game->cast_data.wall_height;
	top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	bottom = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	if (top < 0)
		top = 0;
	if (bottom >= SCREEN_HEIGHT)
		bottom = SCREEN_HEIGHT - 1;
	draw_ceiling(game, row, 0, top);
	set_wall_textures(game, row, top, bottom);
	draw_floor(game, row, bottom);
}
