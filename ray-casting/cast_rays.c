# include "cub3D.h"

// what you need to start the ray-casting?
	// >>> ray_nbr -> how much rays to cast
	// >>> angle_step -> distance between each ray
    // >>> befor casting any ray we have (player direction)
        // and we need to get the left most ray to cast the first ray to right most
        // ray_angle = player->rot_angle - (rc->fov_angle / 2);
        // ray_angle =         45        -       60       / 2
        // ray_angle = 15 (left-most)
    // >>> horizontal check <<<
        //  x_intersection | y_intersection
        //  A_y = P_y / TILE_SIZE * TILE_SIZE;
        //  A_x = P_x + P_y - A_y / tan(ray_angle)
        //  ---------------------------------------
        //  x_step = TILE_SIZE / tan(ray_angle)
        //  y_step = TILE_SIZE;
    // >>> vertical check <<<
        //  x_intersection | y_intersection
        //  x_step = TILE_SIZE
        //  y_step = TILE_SIZE * tan(ray_angle)

// >>> get the first horizontal hit <<<
// 
void    get_horizontal_intersection(double ray_angle)
{
    // >>> think i have a problem here with the up and down direction
    //     even if ray_angle > 0 && ray_angle < M_PI it shows me U -> up
    //     but i see the problem goes from moving the facing direction
    //     with left arrow with holding it move the facing direction in to
    //     360 degree and steel dwoing me is up
    printf("ray_angle -> %f\n", ray_angle);
    // >>> to check if the player facing down or up for the ray-casting
    if (ray_angle > 0 && ray_angle < M_PI)
        write(1, "Down\n", 5);
    else
        write(1, "Up\n", 3);
}

void    get_vertical_intersection();

void cast_rays(t_game *game)
{
    int     column;
    double  ray_angle;
	
    column = 0;
    // >>> that ray_angle is the angle of the first ray will start from (left-most)
    ray_angle = game->player.angle - (game->player.fov / 2);    // "DONE"

    while (column < game->ray_casting.ray_nbr)
    {
		// >>> just a test
        get_horizontal_intersection(ray_angle);

        // >>> get the next angle for the next ray
        ray_angle += game->ray_casting.angle_step;
        column++;
    }
}
