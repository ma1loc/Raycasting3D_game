# include "cub3D.h"

void    init_ray_config(t_setup *setup)
{
    t_ray_casting   *ray_casting;

    ray_casting = setup->ray_casting;
    ray_casting->ray_nbr = SCREEN_WIDTH;
    ray_casting->fov_angle = degrees_to_radians(FOV);
    ray_casting->angle_step = ray_casting->fov_angle / ray_casting->ray_nbr;

    ray_casting->rays = malloc(sizeof(t_ray_data) * ray_casting->ray_nbr);
    if (!ray_casting->rays)
        return (printf("rays mallocation filed\n"), exit(EXIT_FAILURE));
    ft_memset(ray_casting->rays, 0, sizeof(t_ray_data) * ray_casting->ray_nbr);
}

void cast_rays(t_setup *setup)
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
