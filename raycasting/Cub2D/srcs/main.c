# include "cub2d.h"

// simple 2D map first
// second 3D projection
// North(up), South(down), East(right), and West(left).

t_setup	*setup_struct_init()
{
	t_setup	*setup;

	setup = malloc(sizeof(t_setup));
	if (!setup)
	{
		perror("Failed to allocate memory for setup");
		exit(1);
	}
	
	setup->game = malloc(sizeof(t_game));
	if (!setup->game)
	{
		perror("Failed to allocate memory for game");
		exit(1);
	}
	setup->player = malloc(sizeof(t_player));
	if (!setup->player)
	{
		perror("Failed to allocate memory for game");
		exit(1);
	}
	return (setup);
}


int	main()
{
	t_setup *setup;

	setup = setup_struct_init();
	
	init_game_config(setup->game);
	init_player_config(setup->player, setup->game);
	
	// >>> lession on the key event
	if (setup->game->win_ptr)
		mlx_key_hook(setup->game->win_ptr, key_event, &setup);

	// >>> keep the session alive and display the window without closing it
	mlx_loop(setup->game->mlx_ptr);

	return (0);
}
