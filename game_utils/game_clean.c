# include "cub3D.h"

void	destroy_images(t_game *game)
{
    if (game->window->main_img.img_ptr)
        mlx_destroy_image(game->window->mlx_ptr, game->window->main_img.img_ptr);
	if (game->main_img && game->main_img->img_ptr)
        mlx_destroy_image(game->window->mlx_ptr, game->main_img->img_ptr);
	if (game->textures->t_north.img_ptr)
        	mlx_destroy_image(game->window->mlx_ptr, game->textures->t_north.img_ptr);
	if (game->textures->t_south.img_ptr)
			mlx_destroy_image(game->window->mlx_ptr, game->textures->t_south.img_ptr);
	if (game->textures->t_east.img_ptr)
			mlx_destroy_image(game->window->mlx_ptr, game->textures->t_east.img_ptr);
	if (game->textures->t_west.img_ptr)
			mlx_destroy_image(game->window->mlx_ptr, game->textures->t_west.img_ptr);
	game->textures->t_south.img_ptr = NULL;	
	game->textures->t_north.img_ptr = NULL;
	game->textures->t_east.img_ptr = NULL;
	game->textures->t_west.img_ptr = NULL;
	game->window->main_img.img_ptr = NULL;
	game->main_img->img_ptr = NULL;
}

game_exit(int exit_nbr, char *msg)
{
	if (g_game()->game->window->mlx_ptr)
	{
		// distroy the images
		destroy_images(g_game());
		// distroy the window
		// free the mlx_ptr
	}
	exit(exit_nbr);
}
