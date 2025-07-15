# include "cub3D.h"

/*
    - have wall distance    "DONE"

	note; projection plane represent full FOV
    - 1# get projection plane distance
		>>> i have to get first the (projection plane distance) and
			after that i can get the wall hieght, to draw it

    -  2# get wall hieght

	- wall projection
*/

void	draw_vertical_line(t_game *game, int x, int wall_height, t_intercept_hit ray_hit)
{
	int	y;
	int	top;
	int	bottom;
	
	if (wall_height > SCREEN_HEIGHT)
		wall_height = SCREEN_HEIGHT;
	
	top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	bottom = (SCREEN_HEIGHT / 2) + (wall_height / 2);

	if (top < 0)
		top = 0;
	if (bottom >= SCREEN_HEIGHT)
		bottom = SCREEN_HEIGHT - 1;
	
	y = 0;
	while (y < top)
	{
		my_mlx_pixel_put(game, x, y, 0);
		y++;
	}
	
	y = top;
	while (y < bottom)
	{
		// my_mlx_pixel_put(game, x, y, color);
		if (ray_hit.inter_dir == North)
			my_mlx_pixel_put(game, x, y, RED_COLOR);
		if (ray_hit.inter_dir == South)
			my_mlx_pixel_put(game, x, y, YELLOW_COLOR);

		if (ray_hit.inter_dir == East)
			my_mlx_pixel_put(game, x, y, GREEN_CLOOR);

		if (ray_hit.inter_dir == West)
			my_mlx_pixel_put(game, x, y, WAITE_COLOR);
		y++;
	}
	
	y = bottom;
	while (y < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(game, x, y, 0);
		y++;
	}
}

void	front_view_randring(t_game *game)
{
	int				column;
	double			ray_angle;
	t_intercept_hit obj_hit;
	double			wall_height;

	(void)obj_hit;
	column = 0;
	ray_angle = game->player.angle - (game->player.fov / 2);
	while (column < game->cast_data.ray_nbr)
	{
		while (ray_angle < 0)
			ray_angle += 2 * M_PI;
		while (ray_angle >= 2 * M_PI)
			ray_angle -= 2 * M_PI;
		
		obj_hit = cast_ray(game, ray_angle);

		// wall_height = (TILE_SIZE / game->cast_data.wall_dist) * ((SCREEN_WIDTH / 2)  / tan(game->player.fov));
		wall_height = (TILE_SIZE / game->cast_data.wall_dist) * ((SCREEN_HEIGHT / 2) / tan(game->player.fov / 2));
		
		draw_vertical_line(game, column, wall_height, obj_hit);

		ray_angle += game->cast_data.angle_step;
		column++;
	}
}
