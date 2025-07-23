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

void	set_wall_textures(t_game *game, t_intercept_hit obj_hit, int row, int column, int floor)
{
    (void)floor;   
    t_image *img;
    int     color;
    double  tex_offset_x;   // >>> get the column


    img = get_img_ptr(game, obj_hit);
    color = *(int *)(img->addr + (row * img->size_line) + (column * (img->bpp / 8)));
    
    // >>> tex_offset_y -> static <<<

    // Y -> row
    // X -> column

    // the tex_offset will stay the same (static value) unlike the tex_offset_y
    if (game->cast_data.horizontal_hit) // >>> hor
        tex_offset_x = fmod(obj_hit.intercept.x, (double)TILE_SIZE);
    else                                // >>> ver
        tex_offset_x = fmod(obj_hit.intercept.y, (double)TILE_SIZE);
    
    // printf("tex_offset_x -> %f\n", tex_offset_x);
    
    // exit(1);
}
