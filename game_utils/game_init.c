# include "cub3D.h"

// "DONE"
void	init_mlx_window()
{
	t_game	*game;

	game = g_game();
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
void	init_textures()
{
	int		i;
	t_game	*game;

	i = -1;
	game = g_game();
	while (++i < 4)
	{
		if (!ft_strncmp(game->config->ids[i].id, "NO", 2))
			game->textures.t_north.t_path = ft_strdup(game->config->ids[i].path);
		else if (!ft_strncmp(game->config->ids[i].id, "SO", 2))
			game->textures.t_south.t_path = ft_strdup(game->config->ids[i].path);
		else if (!ft_strncmp(game->config->ids[i].id, "EA", 2))
			game->textures.t_east.t_path = ft_strdup(game->config->ids[i].path);
		else if (!ft_strncmp(game->config->ids[i].id, "WE", 2))
			game->textures.t_west.t_path = ft_strdup(game->config->ids[i].path);
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
void	set_game_textures()
{
	t_game *game;

	game = g_game();
	image_loader(&game->textures.t_north);
	image_loader(&game->textures.t_south);
	image_loader(&game->textures.t_east);
	image_loader(&game->textures.t_west);
}
