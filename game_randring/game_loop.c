# include "cub3D.h"

void	drow_front_view()
{
	t_game *game
	int	column;

	column = 0;
	while (column <)

	cast_rays(game);
}

void	main_img_randring(t_game *game)
{
	draw_2d_map(game);
	draw_player(game);
	
	mlx_put_image_to_window(game->window.mlx_ptr, 
		game->window.win_ptr, 
		game->window.main_img.img_ptr, 0, 0);
	// >>> the x/y -> 0, 0 means that postio that will start puting the img to the window
}

int	game_loop(t_game *game)
{
	handle_key_press(game);		// key-hadling
	
	main_img_randring(game);	// 2D-top-view




	return (0);
}

