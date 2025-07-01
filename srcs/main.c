# include "cub3D.h"

// 0D from 30D

t_game	*g_game(void)
{
	static t_game	game;

	return (&game);
}

void	game_init();
{
	set_mlx_window();
	init_textures();
	set_game_textures();
	init_player_dir();
}

int	main(int argc, char **argv)
{
	t_game *game;

	g_game() = game;
	if (parsing(argc, argv, &game))
		return (1);	

	game_init();

	mlx_hook(setup->game->window->win_ptr, KeyPress, 1L << 0, key_event, setup);
	mlx_hook(setup->game->window->win_ptr, KeyRelease, 1L << 1, key_release, setup);
	
	mlx_loop(setup->game->window->mlx_ptr);

	return (0);
}
