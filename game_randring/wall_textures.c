/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:58:00 by yanflous          #+#    #+#             */
/*   Updated: 2025/08/06 15:42:21 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_image	*get_img_ptr(t_game *game, t_intercept_hit obj_hit)
{
	t_textures	*textures;

	textures = &game->textures;
	if (obj_hit.inter_dir == North)
		return (&textures->t_north);
	else if (obj_hit.inter_dir == South)
		return (&textures->t_south);
	else if (obj_hit.inter_dir == East)
		return (&textures->t_east);
	return (&textures->t_west);
}

double	get_texture_offset_y(int wall_height, double tex_step_per_pixel)
{
	int		wall_top_offset;
	double	tex_index;

	tex_index = 0;
	wall_top_offset = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	if (wall_top_offset < 0)
		tex_index = (-wall_top_offset) * tex_step_per_pixel;
	else
		tex_index = 0;
	return (tex_index);
}

double	get_tex_slice_hit(t_game *game, t_intercept_hit obj_hit)
{
	double	tex_slice_hit;

	if (game->cast_data.horizontal_hit)
		tex_slice_hit = fmod(obj_hit.intercept.x, TILE_SIZE);
	else
		tex_slice_hit = fmod(obj_hit.intercept.y, TILE_SIZE);
	return (tex_slice_hit);
}

void	set_wall_textures(t_game *game, int row_slice, int ceiling, int floor)
{
	t_image		*img;
	double		tex_step_per_pixel;
	double		tex_index;
	int			wall_top_offset;

	img = get_img_ptr(game, game->cast_data.obj_hit);
	tex_step_per_pixel = (double)img->height / game->cast_data.wall_height;
	tex_index = get_texture_offset_y(
			game->cast_data.wall_height, tex_step_per_pixel);
	game->cast_data.tex_offset_x = get_tex_slice_hit(
			game, game->cast_data.obj_hit);
	wall_top_offset = (ceiling - 1);
	while (++wall_top_offset < floor)
	{
		game->cast_data.tex_offset_y = (int)tex_index % img->height;
		game->cast_data.color = *(int *)(img->addr
				+ game->cast_data.tex_offset_y * img->size_line
				+ game->cast_data.tex_offset_x * (img->bpp / 8));
		my_mlx_pixel_put(
			game, row_slice, wall_top_offset, game->cast_data.color);
		tex_index += tex_step_per_pixel;
	}
}
