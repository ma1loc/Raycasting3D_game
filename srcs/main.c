# include "cub3D.h"

// 19D 30D

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

	// >>> set the fov to radians
	player->fov = degrees_to_radians(FOV);
	cast_data->ray_nbr = SCREEN_WIDTH;
	// >>> angle_step is the distance between rays
	cast_data->angle_step = (double)player->fov / cast_data->ray_nbr;
	
	// to-do; get it
	/*
		player look straight ahead (center of the screeen)
		half of the screen width (distance from center to the edge)
		half of the FOV is the angle of the half of the screen width
			>>> screen_width / 2 -> opposite side.
			>>> fov / 2 -> angle of the screen_width / 2
			>>> cast_data->proj_plane_dist -> adjacent side
	*/
	cast_data->proj_plane_dist = (
		SCREEN_WIDTH / 2) / tan(player->fov / 2);

	init_floor_ceiling_rgb(game);
	init_mlx_window(game);
	init_textures(game);
	set_game_textures(game);
	init_player_dir(game);
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
