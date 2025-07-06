# include "cub3D.h"

// what you need to start the ray-casting?
	// >>> ray_nbr -> how much rays to cast
	// >>> angle_step -> distance between each ray
    // >>> befor casting any ray we have (player direction)
        // and we need to get the left most ray to cast the first ray to right most
        // ray_angle = player->rot_angle - (rc->fov_angle / 2);
        // ray_angle =         45        -       60       / 2
        // ray_angle = 15 (left-most)


void cast_rays(t_game *game)
{
    int     column;
    double  ray_angle;
	
    column = 0;
    // >>> that ray_angle is the angle of the first ray will start from (left-most)
    ray_angle = game->player.angle - (game->player.fov / 2);    // "DONE"

    while (column < game->ray_casting.ray_nbr)
    {
		// casting later
        printf("ray column -> %d\n", column);

        ray_angle += game->ray_casting.angle_step;
        column++;
    }
}

void    get_vertical_intersection();
void    get_horizontal_intersection();