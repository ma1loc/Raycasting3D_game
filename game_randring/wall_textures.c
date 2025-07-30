/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:58:00 by yanflous          #+#    #+#             */
/*   Updated: 2025/07/30 20:11:07 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_image	*get_img_ptr(t_game *game, t_intercept_hit obj_hit)		// done
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

double	get_tex_slice_hit(t_game *game, t_intercept_hit obj_hit)	// done
{
	double tex_slice_hit;

	if (game->cast_data.horizontal_hit)
		tex_slice_hit = fmod(obj_hit.intercept.x, TILE_SIZE);
	else
		tex_slice_hit = fmod(obj_hit.intercept.y, TILE_SIZE);
	return (tex_slice_hit);
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

double	get_texture_offset_y(int wall_height, double step)
{
	int		wall_top_clipped;
	double	tex_pos;

	tex_pos = 0;
	wall_top_clipped = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	if (wall_top_clipped < 0)
		tex_pos = (-wall_top_clipped) * step;
	else
		tex_pos = 0;
	return (tex_pos);
}

void	set_wall_textures(t_game *game, int row_slice, int ceiling, int floor)
{
	t_image		*img;				// done
	double		tex_step_per_pixel;	// done
	double		tex_slice_hit;		// done
	double		tex_pos;
	int			wall;

	img = get_img_ptr(game, game->cast_data.obj_hit);	// get image addr (to access there px)
	
	/*
		tex_step_per_pixel calculation helps to (streatch or shrenk) the img in the wall
		it's all about how much pixel in the image 
	*/
	tex_step_per_pixel = (double)img->height / game->cast_data.wall_height;
	tex_pos = get_texture_offset_y(game->cast_data.wall_height, tex_step_per_pixel);

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	tex_slice_hit = get_tex_slice_hit(game, game->cast_data.obj_hit);
	game->cast_data.tex_offset_x = (int)((tex_slice_hit / img->width) * img->width);
	
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	// tex_offset_y
	wall = ceiling;
	while (wall < floor)
	{
		game->cast_data.tex_offset_y = (int)tex_pos % img->height;
		
		// ---------------- just adding pixel to the main frame -------------
		game->cast_data.color = *(int *)(img->addr
				+ game->cast_data.tex_offset_y * img->size_line
				+ game->cast_data.tex_offset_x * (img->bpp / 8));
				// + game->cast_data.tex_offset_x * 1);
		my_mlx_pixel_put(game, row_slice, wall, game->cast_data.color);
		// ------------------------------------------------------------------
		tex_pos += tex_step_per_pixel;
		wall++;
	}
}
