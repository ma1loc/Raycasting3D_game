# include "cub3D.h"

// to-do:
// get the idea about the hor/ver
// fix the double ray_step		-> "DONE"
// fix the dividing of the ray	-> "DONE"
// fix the ray-castin in FOV	-> "DONE"
// make the ray hit the wall

// to-remove later on
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
void	x_draw_line(t_game *game, double x0, double y0, double x1, double y1, int color)
{
	double	dx = x1 - x0;
	double	dy = y1 - y0;
	int		steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	double	x_inc = dx / steps;
	double	y_inc = dy / steps;
	double	x = x0;
	double	y = y0;
	int		i = 0;

	while (i <= steps)
	{
		my_mlx_pixel_put(game, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
		i++;
	}
}
// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------


void	draw_front_view(t_game *game)
{
	int				column;
	t_coord			p_pos;
	double			ray_angle;
	t_intercept_hit	ray_hit;

	column = 0;
	p_pos = game->player.p_pos;
	ray_angle = game->player.angle - (game->player.fov / 2);
	while (column < game->cast_data.ray_nbr)
	{

		// to-do; >>> check the cast-ray <<<
		ray_hit = cast_ray(game, ray_angle);

		// just a test
		// printf("----------- final interception -----------\n");
		// printf("inter_x -> %f\n", ray_hit.intercept.x);
		// printf("inter_y -> %f\n", ray_hit.intercept.y);

		// >>> this like just an test of the ray is cast correctly before the 3d set
		if (ray_hit.inter_dir == North)
			x_draw_line(game, p_pos.x, p_pos.y, ray_hit.intercept.x, ray_hit.intercept.y, BLUE_COLOR);
		if (ray_hit.inter_dir == South)
			x_draw_line(game, p_pos.x, p_pos.y, ray_hit.intercept.x, ray_hit.intercept.y, YELLOW_COLOR);
		if (ray_hit.inter_dir == East)
			x_draw_line(game, p_pos.x, p_pos.y, ray_hit.intercept.x, ray_hit.intercept.y, WAITE_COLOR);
		if (ray_hit.inter_dir == West)
			x_draw_line(game, p_pos.x, p_pos.y, ray_hit.intercept.x, ray_hit.intercept.y, GREEN_CLOOR);

		ray_angle += game->cast_data.angle_step;
		column++;
	}
}





// >>> main game randring engine start here <<<
int	game_loop(t_game *game)
{
	handle_key_press(game);		// key-hadling -> "DONE"

	// 2D-top-view	-> just a test
	draw_2d_map(game);
	draw_player(game);

	draw_front_view(game);		// >>> currently working here <<<

	mlx_put_image_to_window(game->window.mlx_ptr, 
		game->window.win_ptr, 
		game->window.main_img.img_ptr, 0, 0);

	return (0);
}
