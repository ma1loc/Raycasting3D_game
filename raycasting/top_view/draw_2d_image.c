# include "cub3D.h"


// void	draw_top_view_map(t_game *game, t_player *player)
// {
// 	int	row;
// 	int col;

// 	(void)player;

// 	row = -1;
// 	while (game->map[++row])
// 	{
// 		col = -1;
// 		while (game->map[row][++col])
// 		{
// 			if (game->map[row][col] == '1')
// 				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 					game->top_view->wall_img, col * TILE_SIZE, row * TILE_SIZE);
// 			else 
// 				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 					game->top_view->free_space_img, col * TILE_SIZE, row * TILE_SIZE);
// 		}
// 	}
// 	// mlx_put_image_to_window(
// 	// 	game->mlx_ptr,
// 	// 	game->win_ptr,
// 	// 	game->top_view->player_img,
// 	// 	(int)(player->p_x * TILE_SIZE),
// 	// 	(int)(player->p_y * TILE_SIZE));
// }


// void	draw_player_dot(t_player *player, t_game *game)
// {
// 	double	pixel_x;
// 	double	pixel_y;
// 	int		radius;
// 	int		dx;
// 	int		dy;

// 	pixel_x = player->p_x * TILE_SIZE;
// 	pixel_y = player->p_y * TILE_SIZE;
	
// 	radius = 4;
// 	dx = -radius;	// >>> col
// 	while (dx <= radius)
// 	{
// 		dy = -radius;	// >>> row
// 		while (dy <= radius)
// 		{
// 			if (dx * dx + dy * dy <= radius * radius)
// 				mlx_pixel_put(game->mlx_ptr, game->win_ptr,
// 					(int)(pixel_x + dx + 0.5), (int)(pixel_y + dy + 0.5), RED_COLOR);
// 			dy++;
// 		}
// 		dx++;
// 	}
// }
