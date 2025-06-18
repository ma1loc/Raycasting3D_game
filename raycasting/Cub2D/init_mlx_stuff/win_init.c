# include "cub2d.h"

// done //
void	open_window(t_setup *setup)
{
	// >>> screen width and height, just in case for later use
	t_game	*game;
	int 	full_width;
	int 	full_height;

	game = setup->game;
	game->screen_width = SCREEN_WIDTH;
	game->screen_height = SCREEN_HEIGHT;
	mlx_get_screen_size(setup->game->mlx_ptr, &full_width, &full_height);	
	if (SCREEN_WIDTH > full_width)
		game->screen_width = full_width;
	if (SCREEN_HEIGHT > full_height)
		game->screen_height = full_height;
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	setup->game->win_ptr = mlx_new_window(setup->game->mlx_ptr, game->screen_width, game->screen_height, "Cub2D");
	if (!setup->game->mlx_ptr || !setup->game->win_ptr)
	{
		perror("Failed to create MLX window");
		exit(EXIT_FAILURE);
	}
}