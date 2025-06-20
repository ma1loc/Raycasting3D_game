# include "cub3d.h"

// simple 2D map first
// second 3D projection
// North(up), South(down), East(right), and West(left).
// flickering to fix
// pressed keyyyyyyyyyyyyyyyy

int	main()
{
	t_setup *setup;

	setup = setup_struct_init();
	
	init_game_config(setup->game);	// init t_game
	init_player_config(setup->player, setup->game);	// init t_player

	// draw_map(setup->game);
	// draw_player_dot(setup->player, setup->game);
	
	mlx_key_hook(setup->game->win_ptr, key_event, setup);
	// mlx_hook(setup->game->win_ptr, 17, 0, NULL, NULL);
	// mlx_loop_hook(setup->game->mlx_ptr);
	mlx_loop(setup->game->mlx_ptr);

	return (0);
}
