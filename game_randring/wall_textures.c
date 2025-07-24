# include "cub3D.h"

t_image *get_img_ptr(t_game *game, t_intercept_hit obj_hit)
{
	t_textures *textures;

	textures = &game->textures;
	if (obj_hit.inter_dir == North)
        return (&textures->t_north);
    else if (obj_hit.inter_dir == South)
    	return (&textures->t_south);
    else if (obj_hit.inter_dir == East)
    	return (&textures->t_east);
    return (&textures->t_west);
}

// Y -> row
// X -> column

// // >>> set_wall_texture is for draw a vertical strip of wall
// void	set_wall_textures(
// 	t_game *game, t_intercept_hit obj_hit, int x, int top, int bottom)
// {
//     t_image *img;
//     double  step;
//     int		tex_offset_y;
//     int		tex_offset_x;
//     double  tex_pos;
//     int     color;
// 	int		y;

// 	tex_pos = 0;
//     img = get_img_ptr(game, obj_hit);	// >>> DONE
// 	/*
// 		stretching detail
// 		shrinking less detail
// 		stretching && shrinking based on the wall the wall is be and how far wall is
// 		and that all done by the step
// 	    step = (double)img->height / (floor - ceiling);
// 	*/

//     step = (double)img->height / (bottom - top);
// 	y = top;


// 	// if (game->cast_data.horizontal_hit)
// 	// 	tex_offset_x = (int)(fmod(obj_hit.intercept.x, TILE_SIZE) * img->width / TILE_SIZE);
// 	// else
// 	// 	tex_offset_x = (int)(fmod(obj_hit.intercept.y, TILE_SIZE) * img->width / TILE_SIZE);


// 	double wall_x;

// 	if (game->cast_data.horizontal_hit)
// 	{
// 		wall_x = obj_hit.intercept.x;
// 		if (obj_hit.inter_dir == South)
// 			wall_x = TILE_SIZE - fmod(wall_x, TILE_SIZE);
// 		else
// 			wall_x = fmod(wall_x, TILE_SIZE);
// 	}
// 	else
// 	{
// 		wall_x = obj_hit.intercept.y;
// 		if (obj_hit.inter_dir == West)
// 			wall_x = TILE_SIZE - fmod(wall_x, TILE_SIZE);
// 		else
// 			wall_x = fmod(wall_x, TILE_SIZE);
// 	}

// tex_offset_x = (int)(wall_x * img->width / TILE_SIZE);

// 	while (y < bottom)
//     {
//         tex_offset_y = (int)tex_pos;    // >>> row

// 		color = (*(int *)(img->addr + 
// 			(tex_offset_y * img->size_line) +
// 			(tex_offset_x * (img->bpp / 8))));

//         my_mlx_pixel_put(game, x, y, color);
//         tex_pos += step;
//         y++;
//     }
// }

void set_wall_textures(
    t_game *game, t_intercept_hit obj_hit, int x, int top, int bottom)
{
    t_image *img;
    double step;
    int tex_offset_y;
    int tex_offset_x;
    double tex_pos;
    int color;
    int y;

    tex_pos = 0;
    img = get_img_ptr(game, obj_hit);
    step = (double)img->height / (bottom - top);
    y = top;

    // Simple texture coordinate calculation
    if (game->cast_data.horizontal_hit)
        tex_offset_x = (int)obj_hit.intercept.x & 63;  // & 63 is same as % 64
    else
        tex_offset_x = (int)obj_hit.intercept.y & 63;

    while (y < bottom)
    {
        tex_offset_y = (int)tex_pos & 63;  // & 63 is same as % 64
        
        color = (*(int *)(img->addr +
            (tex_offset_y * img->size_line) +
            (tex_offset_x * (img->bpp / 8))));
        
        my_mlx_pixel_put(game, x, y, color);
        tex_pos += step;
        y++;
    }
}