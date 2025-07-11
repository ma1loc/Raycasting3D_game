# include "cub3D.h"

// to-do:
// get the idea about the hor/ver



// >>> main game randring engine start here <<<
int	game_loop(t_game *game)
{
	handle_key_press(game);		// key-hadling -> "DONE"

	// >>> 2D-top-view	-> just a test
	draw_2d_map(game);
	draw_player(game);
	// ---------------------------

	// >>> draw rays of 2d player
	draw_rays_view(game);		// >>> currently working here <<<

	mlx_put_image_to_window(game->window.mlx_ptr, 
		game->window.win_ptr, 
		game->window.main_img.img_ptr, 0, 0);

	return (0);
}
