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
// >>> set_wall_texture is for draw a vertical strip of wall
void set_wall_textures(
    t_game *game, t_intercept_hit obj_hit, int x, int top,
    int bottom, int wall_height)
{
    int y;
    double step;
    t_image *img;
    int color;
    int tex_offset_x;
    int tex_offset_y;
    double hit_pos;
    
    
    y = top;
    /*
		stretching detail
		shrinking less detail
		stretching && shrinking based on the wall the wall is be and how far wall is
		and that all done by the step
	    step = (double)img->height / (floor - ceiling);
	*/
    img = get_img_ptr(game, obj_hit);
    step = (double)img->height / wall_height;

    // Calculate how many pixels are clipped at the top of the wall slice
    int wall_top_clipped = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    double tex_pos = 0;

    if (wall_top_clipped < 0)
        tex_pos = (-wall_top_clipped) * step;
    else
        tex_pos = 0;

    // Calculate texture X coordinate properly (fractional position on tile)
    if (game->cast_data.horizontal_hit)
        hit_pos = fmod(obj_hit.intercept.x, TILE_SIZE);
    else
        hit_pos = fmod(obj_hit.intercept.y, TILE_SIZE);
    // if (hit_pos < 0)
    //     hit_pos += TILE_SIZE;

    if (hit_pos < 0)
        printf("hit_pos -> %f\n", hit_pos);
    tex_offset_x = (int)((hit_pos / TILE_SIZE) * img->width);

    while (y < bottom)
    {
        tex_offset_y = (int)tex_pos % img->height;
        
        color = *(int *)(img->addr +
            tex_offset_y * img->size_line +
            tex_offset_x * (img->bpp / 8));

        my_mlx_pixel_put(game, x, y, color);
        tex_pos += step; 
        y++;
    }
}
