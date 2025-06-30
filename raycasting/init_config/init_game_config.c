# include "cub3D.h"

void	open_window(t_game *game)
{
	int full_width;
	int full_height;
	int	screen_width;
	int	screen_height;

	screen_width = SCREEN_WIDTH;
	screen_height = SCREEN_HEIGHT;
	mlx_get_screen_size(game->window->mlx_ptr, &full_width, &full_height);
	if (SCREEN_WIDTH > full_width)
		screen_width = full_width;
	if (SCREEN_HEIGHT > full_height)
		screen_height = full_height;
	game->window->win_ptr = mlx_new_window(game->window->mlx_ptr, screen_width, screen_height, "Cub3D");
	if (!game->window->win_ptr)
	{
		perror("Failed to create MLX window");
		exit(EXIT_FAILURE);
	}
}

void	set_mlx_window(t_game *game)
{
	game->window->mlx_ptr = mlx_init();
	if (!game->window->mlx_ptr)
		return (printf("mlx_init filed\n"), exit(EXIT_FAILURE), (void)0);

	open_window(game);
}
