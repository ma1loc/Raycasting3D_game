# include "cub3D.h"

void draw_ceiling(t_game *game, int row, int column, int ceiling)
{
	int	ceiling_color;

	ceiling_color = game->window.ceiling_color;
    while (column < ceiling)
    {
        my_mlx_pixel_put(game, row, column, ceiling_color);
        column++;
    }
}

void draw_floor(t_game *game, int row, int column)
{
	int	floor_color;

	floor_color = game->window.floor_color;
    while (column < SCREEN_HEIGHT)
    {
        my_mlx_pixel_put(game, row, column, floor_color);
        column++;
    }
}

/*
    >>> the next process is set the texture to the wall
        in all the direction (n, s, e, w)
        you need to stretch or shrink the texture vertically
*/

void draw_wall(
    t_game *game, t_intercept_hit ray_hit, int row, int column, int end)
{
    while (column < end)
    {
        if (ray_hit.inter_dir == North)
            my_mlx_pixel_put(game, row, column, RED_COLOR);
        if (ray_hit.inter_dir == South)
            my_mlx_pixel_put(game, row, column, YELLOW_COLOR);
        if (ray_hit.inter_dir == East)
            my_mlx_pixel_put(game, row, column, GREEN_COLOR);
        if (ray_hit.inter_dir == West)
            my_mlx_pixel_put(game, row, column, BLUE_COLOR);
        column++;
    }
}

void draw_column_line(
    t_game *game, t_intercept_hit obj_hit, int row, int wall_height)
{
    int ceiling;
    int floor;
    

    // >>> if the wall height then screen_height limitaion to SCREEN_HEIGHT
    if (wall_height > SCREEN_HEIGHT)
        wall_height = SCREEN_HEIGHT;
    
    // >>> ceiling gives you ceiling space column to draw
    ceiling = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    // >>> floor gives you floor space column to draw
    floor = (SCREEN_HEIGHT / 2) + (wall_height / 2);
    
    // >>> if, set to defult
    if (ceiling < 0)
        ceiling = 0;
    if (floor >= SCREEN_HEIGHT)
        floor = SCREEN_HEIGHT - 1;

    draw_ceiling(game, row, 0, ceiling);
	
	// >>> set texture to the wall <<<
    // draw_wall(game, obj_hit, row, ceiling, floor);
	set_wall_textures(game, obj_hit, row, ceiling, floor);
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
	draw_floor(game, row, floor);
}
