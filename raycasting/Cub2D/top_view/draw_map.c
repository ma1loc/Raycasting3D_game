# include "cub3d.h"

void	draw_tile(t_game *game, int col, int row, int color)
{
	int	i;
	int j;

	i = -1;
	while (++i < TILE_SIZE)
	{
		j = -1;
		while (++j < TILE_SIZE)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr,
				col * TILE_SIZE + j, row * TILE_SIZE + i, color);
	}
}

void	draw_map(t_game *game)
{
	int	row;
	int col;

	row = -1;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
			if (game->map[row][col] == '1')
				draw_tile(game, col, row, D_GRAY_COLOR);
			else 
				draw_tile(game, col, row, GRAY_COLOR);
		}
	}
}

// void	draw_player_dot(t_player *player, t_game *game)
// {
// 	int	x = player->p_x * TILE_SIZE;
// 	int	y = player->p_y * TILE_SIZE;
// 	int	radius_outer = 4; // stroke (black)
// 	int	radius_inner = 3; // core (red)

// 	for (int dx = -radius_outer; dx <= radius_outer; dx++)
// 	{
// 		for (int dy = -radius_outer; dy <= radius_outer; dy++)
// 		{
// 			int dist2 = dx * dx + dy * dy;
// 			if (dist2 <= radius_outer * radius_outer)
// 			{
// 				int color = (dist2 <= radius_inner * radius_inner) ? 0xFF0000 : 0x000000;
// 				mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + dx, y + dy, color);
// 			}
// 		}
// 	}
// }

// Correct:



// void	draw_player_dot(t_player *player, t_game *game)
// {
// 	// first thing we have to know the player direction
// 	int	pixel_x;
// 	int	pixel_y;
// 	int	radius;
	
// 	// >>> my question is i workd with the (TILE_SIZE = 32) in the 3d view and 2d
// 	int pixel_x = player->p_x * TILE_SIZE; // column → horizontal → x
// 	int pixel_y = player->p_y * TILE_SIZE; // row → vertical → y
// 	radius = 4;



// }