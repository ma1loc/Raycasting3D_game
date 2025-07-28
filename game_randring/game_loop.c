/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:56:00 by yanflous          #+#    #+#             */
/*   Updated: 2025/07/28 20:28:23 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	front_view_randring(t_game *game)
{
	int				column;
	double			ray_angle;
	t_cast_data		*cast_data;
	double			wall_height;
	double			correct_wall_dist;

	column = -1;
	cast_data = &game->cast_data;
	ray_angle = game->player.angle - (game->player.fov / 2);
	while (++column < cast_data->ray_nbr)
	{
		ray_angle = normalize_angle(ray_angle);
		cast_data->obj_hit = cast_ray(game, ray_angle);
		correct_wall_dist = (cast_data->wall_dist
				* cos(ray_angle - game->player.angle));
		cast_data->wall_dist = correct_wall_dist;
		wall_height = ((TILE_SIZE / correct_wall_dist)
				* cast_data->proj_plane_dist);
		game->cast_data.wall_height = wall_height;
		draw_column_line(game, column);
		ray_angle += cast_data->angle_step;
	}
}

int	game_loop(t_game *game)
{
	handle_key_press(game);		// done_n
	front_view_randring(game);
	mlx_put_image_to_window(game->window.mlx_ptr,
		game->window.win_ptr,
		game->window.main_img.img_ptr, 0, 0);
	return (0);
}
