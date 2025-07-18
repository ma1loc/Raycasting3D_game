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

void draw_wall(
    t_game *game, t_intercept_hit ray_hit, int row, int start, int end)
{
    while (start < end)
    {
        if (ray_hit.inter_dir == North)
            my_mlx_pixel_put(game, row, start, RED_COLOR);
        if (ray_hit.inter_dir == South)
            my_mlx_pixel_put(game, row, start, YELLOW_COLOR);
        if (ray_hit.inter_dir == East)
            my_mlx_pixel_put(game, row, start, GREEN_COLOR);
        if (ray_hit.inter_dir == West)
            my_mlx_pixel_put(game, row, start, BLUE_COLOR);
        start++;
    }
}

void draw_column_line(
    t_game *game, t_intercept_hit ray_hit, int row, int wall_height)
{
    int ceiling;
    int floor;
    
    (void)ray_hit;

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
    draw_wall(game, ray_hit, row, ceiling, floor);
    draw_floor(game, row, floor);
}
