# include "cub3D.h"

void cast_rays()
{
    int column;
    t_player *player;
    t_ray_casting *rc;
    double ray_angle;
    
	column = 0;
	player = setup->player;
	rc = setup->ray_casting;
    ray_angle = player->rot_angle - (rc->fov_angle / 2);
    while (column < rc->ray_nbr)
    {
		// casting later
        ray_angle += rc->angle_step;
        column++;
    }
}
