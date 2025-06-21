# include "cub3d.h"

// simple 2D map first
// second 3D projection
// North(up), South(down), East(right), and West(left).
// flickering to fix
// pressed keyyyyyyyyyyyyyyyy
// to create my_mlx_put_pixel() later on
// >>>>>>>>>>>>>>>>>>> TO kNOW <<<<<<<<<<<<<<<<<<<<<<
	// i think about the mlx as engen taht i have to start it (mlx_init) to get start woking with it
	// to knwo why the mlx_put_pixel flickering and slow?
	// to know how mlx_do_key_autorepeaton(void *mlx_ptr) work?
	// to know what the fucking diff mlx_hook, mlx_loop_hook, mlx_loop

int	main()
{
	t_setup *setup;

	setup = setup_struct_init();
	
	init_game_config(setup->game);

	init_player_config(setup);

	load_images_top_view(setup);

	draw_top_view_map(setup->game, setup->player);

	draw_player_dot(setup->player, setup->game);

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// just listener in the key pressed
	mlx_key_hook(setup->game->win_ptr, key_event, setup);

	
	// mlx_do_key_autorepeaton(setup->game->mlx_ptr);
	// mlx_key_autorepeat_on(setup->game->mlx_ptr);
	mlx_do_key_autorepeaton(setup->game->mlx_ptr);

	// mlx_hook(setup->game->win_ptr, 17, 0, NULL, NULL);
	// mlx_loop_hook(setup->game->mlx_ptr);
	
	// mlx_hook(win, 2, 0, key_press, setup);
	// mlx_hook(win, 3, 0, key_release, setup);
	// mlx_loop_hook(mlx_ptr, update, setup);
	// mlx_loop(mlx_ptr);
	
	mlx_loop(setup->game->mlx_ptr);
	

	return (0);
}
