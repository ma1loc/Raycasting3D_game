# include "cub3D.h"

void	t_path_destroy(t_game *game)
{
	if (game->textures->t_north.t_path)
		free(game->textures->t_north.t_path);
	if (game->textures->t_south.t_path)
		free(game->textures->t_south.t_path);
	if (game->textures->t_east.t_path)
		free(game->textures->t_east.t_path);
	if (game->textures->t_west.t_path)
		free(game->textures->t_west.t_path);
}

void	destroy_texture_images(t_game *game)
{
	if (game->textures->t_north.img_ptr)
    	mlx_destroy_image(game->window->mlx_ptr, game->textures->t_north.img_ptr);
	if (game->textures->t_south.img_ptr)
		mlx_destroy_image(game->window->mlx_ptr, game->textures->t_south.img_ptr);
	if (game->textures->t_east.img_ptr)
		mlx_destroy_image(game->window->mlx_ptr, game->textures->t_east.img_ptr);
	if (game->textures->t_west.img_ptr)
		mlx_destroy_image(game->window->mlx_ptr, game->textures->t_west.img_ptr);
	t_path_destroy(game);
}

void	game_exit(int exit_nbr, char *msg)
{
	t_game *game;

	game = g_game();
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);

	if (game->map)
	    free_map(g_game());
	if (game->config)
	    free_config(g_game());

	if (g_game()->game->window->mlx_ptr)
	{
		destroy_texture_images(g_game());
		destory_window(g_game()->game->window->win_ptr);
	}
	if (game->window && game->window->mlx_ptr)
    {
        destroy_texture_images(game);
        if (game->window->win_ptr)
            mlx_destroy_window(game->window->mlx_ptr, game->window->win_ptr);
        if (game->window->main_img.img_ptr)
            mlx_destroy_image(game->window->mlx_ptr, game->window->main_img.img_ptr);
    }
	exit(exit_nbr);
}
