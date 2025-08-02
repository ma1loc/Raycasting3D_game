/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:56:00 by yanflous          #+#    #+#             */
/*   Updated: 2025/08/02 13:36:01 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	front_view_randring(t_game *game)
{
	int				slice;
	double			ray_angle;
	t_cast_data		*cast_data;
	double			angle_difference;

	slice = -1;
	cast_data = &game->cast_data;
	ray_angle = game->player.angle - (game->player.fov / 2);
	while (++slice < cast_data->ray_nbr)
	{
		ray_angle = normalize_angle(ray_angle);
		cast_data->obj_hit = cast_ray(game, ray_angle);
		angle_difference = game->player.angle - ray_angle;
		cast_data->wall_dist = (cast_data->wall_dist * cos(angle_difference));
		game->cast_data.wall_height = ((TILE_SIZE / cast_data->wall_dist)
				* cast_data->proj_plane_dist);
		draw_slice(game, slice);
		ray_angle += cast_data->angle_step;
	}
}

int	game_loop(t_game *game)
{
	handle_key_press(game);
	front_view_randring(game);
	mlx_put_image_to_window(game->window.mlx_ptr,
		game->window.win_ptr,
		game->window.main_img.img_ptr, 0, 0);
	return (0);
}
