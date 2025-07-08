# include "cub3D.h"

// just a test to remove it later
// void	draw_ray(t_game *game, double x0, double y0, double x1, double y1, int color)
// {
// 	double	dx = x1 - x0;
// 	double	dy = y1 - y0;
// 	int		steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
// 	double	x_step = dx / steps;
// 	double	y_step = dy / steps;
// 	int		i = 0;

// 	while (i < steps)
// 	{
// 		my_mlx_pixel_put(game, (int)x0, (int)y0, color);
// 		x0 += x_step;
// 		y0 += y_step;
// 		i++;
// 	}
// }



void	check_intersection_hit(t_game *game, t_coord intercept, t_coord step)
{

}

// ----------- start the horizontal intersection -----------
// to_do -> have to get the player facing direction (n, s, e, w)
t_intercept_hit	get_horizontal_intersection(t_game *game, t_coord p_pos, double ray_angle)
{
    double      slope;
    t_coord     intercept;
    t_coord     step;

    slope = tan(ray_angle);
    if (ray_angle > 0 && ray_angle < M_PI)
    {
		// >>> facing down mean's south
        intercept.y = floor(p_pos.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
        step.y = TILE_SIZE;
    }
    else
    {
		// >>> facing down mean's north
		intercept.y = floor(p_pos.y / TILE_SIZE) * TILE_SIZE - 0.001;
        step.y = -TILE_SIZE;
    }
    intercept.x = p_pos.x + (intercept.y - p_pos.y) / slope;
    step.x = step.y / slope;

	check_intersection_hit(game, intercept, step);
}

// void    get_vertical_intersection(t_game *game, double ray_angle)
// {
//     double  slope;
//     t_coord *p_pos;
//     t_coord step;
//     // t_coord intercept;

//     slope = tan(ray_angle);
//     p_pos = &game->player.p_pos;

//     // get the xstep, based on xstep get the ystep
//     step.x = TILE_SIZE;
//     step.y = step.x / slope;
//     // -----------------------
// }

void cast_rays(t_game *game)
{
    double  ray_angle;
	t_intercept_hit	horizontal_hit;
	t_intercept_hit vertical_hit;
	
    // >>> that ray_angle is the angle of the first ray will start from (left-most)
    ray_angle = game->player.angle - (game->player.fov / 2);    // "DONE"


    horizontal_hit = get_horizontal_intersection(game, game->player.p_pos, ray_angle);
	// vertical_hit = 
    ray_angle += game->cast_data.angle_step;

}
