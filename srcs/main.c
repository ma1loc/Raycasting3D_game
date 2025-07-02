# include "cub3D.h"

// 1D from 30D

t_game	*g_game(void)
{
	static t_game	game;

	return (&game);
}

void	game_init()
{
	// >>> first thing is to set mlx window
	init_mlx_window();		// "DONE"
	init_textures();		// "DONE"
	set_game_textures();	// "DONE"
	init_player_dir();		// "N_DONE"
}

int	main(int argc, char **argv)
{
	t_game *game;

	game = g_game();
	(void)game;
	if (parsing(argc, argv, g_game()))
		return (1);	

	game_init();

	mlx_hook(game->window->win_ptr, KeyPress, 1L << 0, key_press, NULL);
	mlx_hook(game->window->win_ptr, KeyRelease, 1L << 1, key_release, NULL);
	// mlx_loop_hook(game->window->win_ptr, game_loop, game);
	// mlx_loop(game->window->mlx_ptr);

	game_exit(0, NULL);
	return (0);
}
