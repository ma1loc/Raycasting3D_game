/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_view_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:55:55 by yanflous          #+#    #+#             */
/*   Updated: 2025/08/02 13:25:54 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_ceiling(t_game *game, int row_slice, int column, int ceiling)
{
	int	ceiling_color;

	ceiling_color = game->window.ceiling_color;
	while (column < ceiling)
	{
		my_mlx_pixel_put(game, row_slice, column, ceiling_color);
		column++;
	}
}

void	draw_floor(t_game *game, int row_slice, int column)
{
	int	floor_color;

	floor_color = game->window.floor_color;
	while (column < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(game, row_slice, column, floor_color);
		column++;
	}
}

void	draw_slice(t_game *game, int row_slice)
{
	int	ceiling;
	int	floor;
	int	wall_height;

	wall_height = game->cast_data.wall_height;
	ceiling = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	floor = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	if (ceiling < 0)
		ceiling = 0;
	if (floor >= SCREEN_HEIGHT)
		floor = SCREEN_HEIGHT;
	draw_ceiling(game, row_slice, 0, ceiling);
	set_wall_textures(game, row_slice, ceiling, floor);
	draw_floor(game, row_slice, floor);
}
