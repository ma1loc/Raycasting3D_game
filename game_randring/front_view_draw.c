#include "cub3D.h"

void draw_ceiling(t_game *game, int row, int column, int ceiling)
{
	int ceiling_color;

	ceiling_color = game->window.ceiling_color;
	while (column < ceiling)
	{
		my_mlx_pixel_put(game, row, column, ceiling_color);
		column++;
	}
}

void draw_floor(t_game *game, int row, int column)
{
	int floor_color;

	floor_color = game->window.floor_color;
	while (column < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(game, row, column, floor_color);
		column++;
	}
}

void draw_column_line(
	t_game *game, t_intercept_hit obj_hit, int row, int wall_height)
{
	int top;
	int bottom;

	// >>> if the wall height then screen_height limitaion to SCREEN_HEIGHT
	if (wall_height > SCREEN_HEIGHT)
		wall_height = SCREEN_HEIGHT;

	// >>> ceiling gives you ceiling space column to draw
	top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	// >>> floor gives you floor space column to draw
	bottom = (SCREEN_HEIGHT / 2) + (wall_height / 2);

	// >>> if, set to defult
	if (top < 0)
		top = 0;
	if (bottom >= SCREEN_HEIGHT)
		bottom = SCREEN_HEIGHT - 1;

	draw_ceiling(game, row, 0, top);
	set_wall_textures(game, obj_hit, row, top, bottom);
	draw_floor(game, row, bottom);
}
