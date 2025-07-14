# include "cub3D.h"

// >>> main game randring engine start here <<<
int	game_loop(t_game *game)
{
	handle_key_press(game);	// key-hadling

	// >>> 2D-top-view
	/*
		draw_2d_map(game);
		draw_player(game);	
		draw_rays_view(game);
	*/
	
	// >>> 3D-front view
	front_view_randring(game);
	

	mlx_put_image_to_window(game->window.mlx_ptr, 
		game->window.win_ptr, 
		game->window.main_img.img_ptr, 0, 0);

	return (0);
}
