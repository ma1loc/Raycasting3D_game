/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:58:00 by yanflous          #+#    #+#             */
/*   Updated: 2025/08/02 13:34:54 by yanflous         ###   ########.fr       */
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

double	get_tex_slice_hit(t_game *game, t_intercept_hit obj_hit)
{
	double	tex_slice_hit;

	if (game->cast_data.horizontal_hit)
		tex_slice_hit = fmod(obj_hit.intercept.x, TILE_SIZE);
	else
		tex_slice_hit = fmod(obj_hit.intercept.y, TILE_SIZE);
	return (tex_slice_hit);
}

double	get_texture_offset_y(int wall_height, double tex_step_per_pixel)
{
	int		wall_top_offset;
	double	tex_pos;

	tex_pos = 0;
	wall_top_offset = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	if (wall_top_offset < 0)
		tex_pos = (-wall_top_offset) * tex_step_per_pixel;
	else
		tex_pos = 0;
	return (tex_pos);
}

void	set_wall_textures(t_game *game, int row_slice, int ceiling, int floor)
{
	t_image		*img;
	double		tex_step_per_pixel;
	double		tex_slice_hit;
	double		tex_pos;
	int			wall_top_offset;

	img = get_img_ptr(game, game->cast_data.obj_hit);
	tex_step_per_pixel = (double)img->height / game->cast_data.wall_height;
	tex_pos = get_texture_offset_y(
			game->cast_data.wall_height, tex_step_per_pixel);
	tex_slice_hit = get_tex_slice_hit(
			game, game->cast_data.obj_hit);
	game->cast_data.tex_offset_x = ((int)((tex_slice_hit / img->width)
				* img->width));
	wall_top_offset = (ceiling - 1);
	while (++wall_top_offset < floor)
	{
		game->cast_data.tex_offset_y = (int)tex_pos % img->height;
		game->cast_data.color = *(int *)(img->addr
				+ game->cast_data.tex_offset_y * img->size_line
				+ game->cast_data.tex_offset_x * (img->bpp / 8));
		my_mlx_pixel_put(
			game, row_slice, wall_top_offset, game->cast_data.color);
		tex_pos += tex_step_per_pixel;
	}
}
