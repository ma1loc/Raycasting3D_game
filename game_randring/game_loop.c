# include "cub3D.h"

void	front_view_randring(t_game *game)
{
	int				column;
	double			ray_angle;
	t_cast_data		*cast_data;
	t_intercept_hit obj_hit;
	double			wall_height;
	double			correct_wall_dist;

	column = -1;
	cast_data = &game->cast_data;
	ray_angle = game->player.angle - (game->player.fov / 2);
	while (++column < game->cast_data.ray_nbr)
	{
		ray_angle = normalize_angle(ray_angle);
		obj_hit = cast_ray(game, ray_angle);
		correct_wall_dist = (cast_data->wall_dist * 
			cos(ray_angle - game->player.angle));
		wall_height = ((TILE_SIZE / correct_wall_dist)
			* cast_data->proj_plane_dist);

		// >>> drawing the 3d projection
		draw_column_line(game, obj_hit, column, wall_height);
		ray_angle += game->cast_data.angle_step;
	}
	// exit(0);	
}


// >>> main game randring engine start here <<<
int	game_loop(t_game *game)
{
	handle_key_press(game);	// key-hadling

	// >>> 2D-top-view
	/*
		draw_2d_map(game);
		draw_player(game);	
		// draw_rays_view(game);
	*/

	// >>> 3D-front view (projection)
	front_view_randring(game);

	mlx_put_image_to_window(game->window.mlx_ptr, 
		game->window.win_ptr, 
		game->window.main_img.img_ptr, 0, 0);

	return (0);
}
