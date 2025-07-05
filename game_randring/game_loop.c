# include "cub3D.h"

void	main_img_randring(t_game *game)
{
	draw_2d_map(game);
	draw_player(game);
	
	mlx_put_image_to_window(game->window.mlx_ptr, 
		game->window.win_ptr, 
		game->window.main_img.img_ptr, 0, 0);
}

int	game_loop(t_game *game)
{
	handle_key_press(game);
	main_img_randring(game);
	return (0);
}

