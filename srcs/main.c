# include "cub3D.h"

// 9D 30D

t_game	*g_game(void)
{
	static t_game	game;

	return (&game);
}

void	game_init(t_game *game)
{
	t_player	*player;
	t_cast_data	*cast_data;

	player = &game->player;
	cast_data = &game->cast_data;
	player->fov = degrees_to_radians(FOV);
	cast_data->ray_nbr = SCREEN_WIDTH;
	cast_data->angle_step = (double)player->fov / cast_data->ray_nbr;
	
	get_map_size(game);
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
	game_init(game);
	mlx_hook(game->window.win_ptr, KeyPress, 1L << 0, key_press, NULL);
	mlx_hook(game->window.win_ptr, KeyRelease, 1L << 1, key_release, NULL);
	mlx_loop_hook(game->window.mlx_ptr, game_loop, game);	// "N_DONE"
	mlx_loop(game->window.mlx_ptr);
	return (0);
}
