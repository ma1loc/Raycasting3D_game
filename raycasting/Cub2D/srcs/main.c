# include "cub2d.h"

// simple 2D map first
// second 3D projection
// North(up), South(down), East(right), and West(left).

void	*setup_struct_init()
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


void	load_player_img(t_player *player, t_game *game)
{
	char	*image_path;
	int		x;
	int		y;

	image_path = "./images_config/player_img.xpm";
	player->player_img = mlx_xpm_file_to_image(game->mlx_ptr, image_path, &x, &y);
	if (!player->player_img)
	{
		printf("player->player_img is filed\n");
		exit(EXIT_FAILURE);
	}
}

// void	load_wall_img(t_player *player, t_game *game)
// {

// }

void	draw_player_img(t_player *player, t_game *game)
{
	int x = player->p_x * TILE_SIZE;
	int y = player->p_y * TILE_SIZE;

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		player->player_img, x - 8, y - 8); // adjust -8 to center the sprite
}

// void	draw_walls_img()


int	main()
{
	t_setup *setup;

	setup = setup_struct_init();
	
	init_game_config(setup->game);	// init t_game
	init_player_config(setup->player, setup->game);	// init t_player

	load_player_img(setup->player, setup->game);
	draw_player_img(setup->player, setup->game);
	
	mlx_key_hook(setup->game->win_ptr, key_event, &setup);

	// >>> keep the session alive and display the window without closing it
	mlx_loop(setup->game->mlx_ptr);

	return (0);
}
