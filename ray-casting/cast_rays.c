/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:01:16 by yanflous          #+#    #+#             */
/*   Updated: 2025/07/29 16:54:10 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_hit(t_game *game, t_coord intercept)
{
	int	map_x;
	int	map_y;

	map_x = (int)(intercept.x / TILE_SIZE);
	map_y = (int)(intercept.y / TILE_SIZE);
	if (map_x < 0 || map_y < 0 || map_y >= game->map_height)
		return (1);
	if (map_x > (int)(ft_strlen(game->map[map_y])))
		return (1);
	return (game->map[map_y][map_x] == '1');
}

t_intercept_hit	check_intersection_hit(
	t_game *game, t_intercept_hit intercept, t_coord step)
{
	while (true)
	{
		if (is_hit(game, intercept.intercept))
			break ;
		intercept.intercept.x += step.x;
		intercept.intercept.y += step.y;
	}
	return (intercept);
}

t_intercept_hit	get_horizontal_intersection(
	t_game *game, t_coord p_pos, double ray_angle)
{
	double			slope;
	t_intercept_hit	intercept;
	t_coord			step;

	slope = tan(ray_angle);
	if (ray_angle > 0 && ray_angle < M_PI)	// south
	{
		intercept.intercept.y = floor(
				p_pos.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		intercept.inter_dir = South;
		step.y = TILE_SIZE;
	}
	else									// north
	{
		intercept.intercept.y = floor(
				p_pos.y / TILE_SIZE) * TILE_SIZE - EPS;	// opposit side
		intercept.inter_dir = North;
		step.y = -TILE_SIZE;	// opposit side
	}
	intercept.intercept.x = p_pos.x + (
			intercept.intercept.y - p_pos.y) / slope;	// adjacent side
	step.x = step.y / slope;	// adjacent side
	return (check_intersection_hit(game, intercept, step));
}

t_intercept_hit	get_vertical_intersection(
	t_game *game, t_coord p_pos, double ray_angle)
{
	double			slope;
	t_intercept_hit	intercept;
	t_coord			step;

	slope = tan(ray_angle);
	if (ray_angle < M_PI / 2 || ray_angle > (M_PI * 3) / 2) // right
	{
		intercept.intercept.x = floor(
				p_pos.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;	// adjacent side
		intercept.inter_dir = East;
		step.x = TILE_SIZE;		// adjacent side
	}
	else													// left
	{
		intercept.intercept.x = floor(
				p_pos.x / TILE_SIZE) * TILE_SIZE - EPS;		// adjacent side
		intercept.inter_dir = West;
		step.x = -TILE_SIZE;	// adjacent side
	}
	intercept.intercept.y = p_pos.y + (
			intercept.intercept.x - p_pos.x) * slope;	// opposit side
	step.y = step.x * slope;	// opposit side
	return (check_intersection_hit(game, intercept, step));
}

t_intercept_hit	cast_ray(t_game *game, double ray_angle)
{
	t_intercept_hit	horizontal_hit;
	t_intercept_hit	vertical_hit;
	t_intercept_hit	result;

	horizontal_hit = get_horizontal_intersection(
			game, game->player.p_pos, ray_angle);
	vertical_hit = get_vertical_intersection(
			game, game->player.p_pos, ray_angle);
	get_closest_distance(
		game, horizontal_hit.intercept, vertical_hit.intercept);
	if (game->cast_data.horizontal_hit)
		result = horizontal_hit;
	else
		result = vertical_hit;
	return (result);
}
