# include "cub3D.h"

// 5D 30D

t_game	*g_game(void)
{
	static t_game	game;

	return (&game);
}

void	game_init()
{
	t_ray_data	*ray_data;
	t_player	*player;

	player = &g_game()->player;
	player->fov = degrees_to_radians(FOV);
	ray_data = &g_game()->ray_casting;
	ray_data->ray_nbr = SCREEN_WIDTH;
	// >>> angle_step -> distance between each ray
	ray_data->angle_step = (player->fov / ray_data->ray_nbr);
	init_mlx_window();
	init_textures();
	set_game_textures();
	init_player_dir();
}

int	main(int argc, char **argv)
{
	t_game *game;

	game = g_game();
	if (parsing(argc, argv, game))
		return (1);	
	game_init();
	mlx_hook(game->window.win_ptr, KeyPress, 1L << 0, key_press, NULL);
	mlx_hook(game->window.win_ptr, KeyRelease, 1L << 1, key_release, NULL);
	mlx_loop_hook(game->window.mlx_ptr, game_loop, game);	// "N_DONE"
	mlx_loop(game->window.mlx_ptr);
	return (0);
}
