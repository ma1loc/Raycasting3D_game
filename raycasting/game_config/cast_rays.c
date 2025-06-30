# include "cub3D.h"


// >>> FOV(60) in the radinas / SCREEN_WIDTH to get the distance between rays 
// >>> rotation_angle is the angle that the player facing
// >>> why i have to subtrating the half of the FOV then i cast the rays?
// >>> create an image buffer / mlx_pixel_put
// >>> have to set the ray thi
// >>> loog thghout the colmuns to cast the rays

// fix the key w, a, s, d, moves 
// number of rays >>> "DONE"
// get the filed of view >>> "DONE"
// subtract the 30 degrees from, ray_angle(player rotation angle - (FOV_ANGLE / 2)) >>> "DONE"
// converting the FOV to randins in fov_angle. >>> "DONE"
// distance btween every ray -> ray_angle += (FOV/NUM_OF_RAYS)? "DONE"
// have to know the wall_distance to drow the wall

// trace the ray until it hit the wall
// how to get the lengh of the ray the cast and hit the wall?
// is the num of rays get from window_width / wall_strip_width ?
// what's mean cast ray ber frame?
// is i have to create an arry of rays?
// So each ray will need its own small struct to store this data.

// >>> before start casting ask what you need before casting rays?
    // - how we cast that ray?
    
    // - how to move to next ray?, this is how, right?; yes
        // >>> ray_casting->ray_angle += ray_casting->angle_step;

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
