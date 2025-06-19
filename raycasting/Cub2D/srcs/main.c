# include "cub3d.h"

// simple 2D map first
// second 3D projection
// North(up), South(down), East(right), and West(left).

int	main()
{
	t_setup *setup;

	setup = setup_struct_init();
	
	init_game_config(setup->game);	// init t_game
	init_player_config(setup->player, setup->game);	// init t_player

	draw_map(setup->game);
	// draw_player_dot(setup->player, setup->game);
	
	mlx_key_hook(setup->game->win_ptr, key_event, &setup);

	// >>> keep the session alive and display the window without closing it
	mlx_loop(setup->game->mlx_ptr);

	return (0);
}
