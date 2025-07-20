# include "cub3D.h"

#define MAX_WIDTH 2944
#define MAX_HEIGHT 1088

// "DONE"
void	init_mlx_window(t_game *game)
{
	game->window.mlx_ptr = mlx_init();

	game->window.win_ptr = mlx_new_window( 
		game->window.mlx_ptr,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		"Cub3D");

	// -- main; create the main frame image --
	game->window.main_img.img_ptr = mlx_new_image(
		game->window.mlx_ptr,
		SCREEN_WIDTH,
		SCREEN_HEIGHT);

	game->window.main_img.addr = mlx_get_data_addr(
		game->window.main_img.img_ptr,
		&game->window.main_img.bpp,
		&game->window.main_img.size_line,
		&game->window.main_img.endian);
	// -------------------------------------

	game->window.main_img.width = SCREEN_WIDTH;
	game->window.main_img.height = SCREEN_HEIGHT;
}

// "DONE"
// void	init_textures()
void	init_textures(t_game *game)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (!ft_strncmp(game->config->ids[i].id, "NO", 2))
			game->textures.t_north.t_path = ft_strdup(
				game->config->ids[i].path);
		else if (!ft_strncmp(game->config->ids[i].id, "SO", 2))
			game->textures.t_south.t_path = ft_strdup(
				game->config->ids[i].path);
		else if (!ft_strncmp(game->config->ids[i].id, "EA", 2))
			game->textures.t_east.t_path = ft_strdup(
				game->config->ids[i].path);
		else if (!ft_strncmp(game->config->ids[i].id, "WE", 2))
			game->textures.t_west.t_path = ft_strdup(
				game->config->ids[i].path);
	}
}

// "DONE"
void	image_loader(t_image *img)
{
	img->img_ptr = mlx_xpm_file_to_image(g_game()->window.mlx_ptr,
		img->t_path, &img->width, &img->height);
	if (!img->img_ptr)
		game_exit(EXIT_FAILURE, "mlx_xpm_file_to_image failed\n");
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp,
		&img->size_line, &img->endian);
}

// "DONE"
void	init_player_dir(t_game *game)
{
	if (*game->player_pos.player == 'N')
		game->player.angle = degrees_to_radians(270);
	else if (*game->player_pos.player == 'S')
		game->player.angle = degrees_to_radians(90);
	else if (*game->player_pos.player == 'E')
		game->player.angle = degrees_to_radians(0);
	else if (*game->player_pos.player == 'W')
		game->player.angle = degrees_to_radians(180);
	game->player.p_pos.x = (game->player_pos.width * TILE_SIZE
		+ (TILE_SIZE / 2));
	game->player.p_pos.y = (game->player_pos.height * TILE_SIZE
		+ (TILE_SIZE / 2));
	game->direction.turn_dir = 0;
	game->direction.walk_dir = 0;
	game->direction.side_dir = 0;
}

// "DONE"
void	set_game_textures(t_game *game)
{
	image_loader(&game->textures.t_north);
	image_loader(&game->textures.t_south);
	image_loader(&game->textures.t_east);
	image_loader(&game->textures.t_west);
}
