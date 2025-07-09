# include "cub3D.h"

void	draw_front_view(t_game *game)
{
	int		column;
	double	ray_angle;

	column = 0;

	ray_angle = game->player.angle - (game->player.fov / 2);
	while (column < game->cast_data.ray_nbr)
	{
		cast_rays(game, ray_angle);
		
		ray_angle += game->cast_data.angle_step;
		column++;
	}

}

void	main_img_randring(t_game *game)
{
	draw_2d_map(game);
	draw_player(game);
	
	mlx_put_image_to_window(game->window.mlx_ptr, 
		game->window.win_ptr, 
		game->window.main_img.img_ptr, 0, 0);
}

int	game_loop(t_game *game)
{
	handle_key_press(game);		// key-hadling
	
	main_img_randring(game);	// 2D-top-view

	draw_front_view(game);		// 3D-from-view


	return (0);
}

