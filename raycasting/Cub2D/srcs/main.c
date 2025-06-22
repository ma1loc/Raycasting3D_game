# include "cub3d.h"

// simple 2D map first
// second 3D projection
// North(up), South(down), East(right), and West(left).
// flickering to fix
// pressed keyyyyyyyyyyyyyyyy
// to create my_mlx_put_pixel() later on
// >>>>>>>>>>>>>>>>>>> TO kNOW && TO-DO <<<<<<<<<<<<<<<<<<<<<<
	// to know what is the steps under the hood calling mlx_init()?
	// i think about the mlx as engen taht i have to start it (mlx_init) to get start woking with it
	// to knwo why the mlx_put_pixel flickering and slow?
	// to know how mlx_do_key_autorepeaton(void *mlx_ptr) work?
	// to know what the fucking diff mlx_hook, mlx_loop_hook, mlx_loop
	// is have to convert the ROT_SPEED to radinas? 
// >>>>>>>>>>>>>>>>>>>>> TO-DO >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// TO-DO: create-function conver form binnary to hex for the colors


int	main()
{
	t_setup *setup;
	
	setup = setup_struct_init();
	init_game_config(setup->game);
	
	
	init_player_config(setup);
	
	load_images_top_view(setup);
	
	draw_top_view_map(setup->game, setup->player);
	
	draw_player_dot(setup->player, setup->game);

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	printf("ccos -> %f\n", cos(degrees_to_radians(FOV)) * 30);
	printf("ssin -> %f\n", sin(degrees_to_radians(FOV)) * 30);
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	mlx_hook(setup->game->win_ptr, KeyPress, 1L << 0, key_event, setup);
	mlx_loop(setup->game->mlx_ptr);

	return (0);
}
