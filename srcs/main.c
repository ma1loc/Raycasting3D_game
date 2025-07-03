# include "cub3D.h"

// 2D from 30D

t_game	*g_game(void)
{
	static t_game	game;

	return (&game);
}

// ---------------------------------------------

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

	mlx_hook(game->window.win_ptr, KeyPress, 1L << 0, key_press, NULL);	// "DONE"
	mlx_hook(game->window.win_ptr, KeyRelease, 1L << 1, key_release, NULL);	// "DONE"
	mlx_loop_hook(game->window.mlx_ptr, game_loop, NULL);	// "N_DONE"

	mlx_loop(game->window.mlx_ptr);

	return (0);
}
