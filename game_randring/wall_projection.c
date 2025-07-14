# include "cub3D.h"

/*
    - have wall distance    "DONE"
    - get projection plane distance
    - get wall hieght

	- wall projection
*/

void	front_view_randring(t_game *game)
{
	int				column;
	double			ray_angle;
	t_intercept_hit obj_hit;

	column = -1;
	ray_angle = game->player.angle - (game->player.fov / 2);
	while (++column < game->cast_data.ray_nbr)
	{
		obj_hit = cast_ray(game, ray_angle);

		// most start here

		ray_angle += game->cast_data.angle_step;
	}
}
