# include "cub3D.h"

// 2D from 30D

t_game	*g_game(void)
{
	static t_game	game;

	return (&game);
}

// ---------------------------------------------

void	image_randring()
{
	t_game *game;

	game = g_game();
	my_mlx_pixel_put(game, 0, 0, RED_COLOR);
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		game->window.main_img.img_ptr, 0, 0);

}

void	game_init()
{
	init_mlx_window();		// "DONE"
	init_textures();		// "DONE"
	set_game_textures();	// "DONE"
	init_player_dir();		// "DONE"
}

int	main(int argc, char **argv)
{
	t_game *game;

	game = g_game();
	if (parsing(argc, argv, g_game()))	// "DONE"
		return (1);	

	game_init();	// "DONE"
	image_randring();	// >>> get the 2d view first

	
	mlx_hook(game->window.win_ptr, KeyPress, 1L << 0, key_press, NULL);
	mlx_hook(game->window.win_ptr, KeyRelease, 1L << 1, key_release, NULL);
	mlx_loop_hook(game->window.mlx_ptr, game_loop, NULL);

	mlx_loop(game->window.mlx_ptr);

	// game_exit(0, NULL);
	return (0);
}
