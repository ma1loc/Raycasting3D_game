# include "cub3D.h"

void	draw_front_view(t_game *game)
{
	int				column;
	double			ray_angle;
	t_intercept_hit	ray_hit;

	column = 0;
	ray_angle = game->player.angle - (game->player.fov / 2);
	while (column < game->cast_data.ray_nbr)
	{
		ray_hit = cast_ray(game, ray_angle);
		// to-do: 
		
		ray_angle += game->cast_data.angle_step;
		column++;
	}
}

// to-remove later on
// ---------------------------------------------------------

// void	x_draw_line(t_game *game, double x0, double y0, double x1, double y1, int color)
// {
// 	double	dx = x1 - x0;
// 	double	dy = y1 - y0;
// 	int		steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
// 	double	x_inc = dx / steps;
// 	double	y_inc = dy / steps;
// 	double	x = x0;
// 	double	y = y0;
// 	int		i = 0;

// 	while (i <= steps)
// 	{
// 		my_mlx_pixel_put(game, (int)x, (int)y, color);
// 		x += x_inc;
// 		y += y_inc;
// 		i++;
// 	}
// }


// void	draw_rays_2d(t_game *game)
// {
// 	int				i;
// 	double			ray_angle;
// 	t_intercept_hit	ray_hit;
// 	t_coord			player;

// 	player = game->player.p_pos;
// 	ray_angle = game->player.angle - (game->player.fov / 2);
// 	i = 0;
// 	while (i < game->cast_data.ray_nbr)
// 	{
// 		ray_hit = cast_ray(game, ray_angle);
// 		x_draw_line(game,
// 			player.x, player.y,
// 			ray_hit.intercept.x, ray_hit.intercept.y,
// 			GREEN_CLOOR);
// 		ray_angle += game->cast_data.angle_step;
// 		printf("game->cast_data.angle_step -> %f\n", game->cast_data.angle_step);
// 		i++;
// 	}
// }

// --------------------------------------------------------------

int	game_loop(t_game *game)
{
	handle_key_press(game);		// key-hadling

	// 2D-top-view
	draw_2d_map(game);
	draw_player(game);

	// draw_rays_2d(game);			// just a test for the rays in 2d

	draw_front_view(game);		// 3D-from-view
	
	// printf("game->cast_data.angle_step %f\n", game->cast_data.angle_step);

	mlx_put_image_to_window(game->window.mlx_ptr, 
		game->window.win_ptr, 
		game->window.main_img.img_ptr, 0, 0);

	return (0);
}

