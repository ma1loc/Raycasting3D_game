# include "cub3D.h"

// ----------- start the horizontal intersection -----------
void    get_horizontal_intersection(t_game *game, double ray_angle)
{
    double      slope;
    t_coord     *p_pos;
    t_coord     intercept;
    t_coord     step;
    t_coord     *hor_hit;

    slope = tan(ray_angle);
    p_pos = &game->player.p_pos;
    hor_hit = &game->cast_data.hor_hit;

    // >>> find the (y-coord) for the first horizontal intersection
    if (ray_angle > 0 && ray_angle < M_PI)  // donw check
    {
        intercept.y = floor(p_pos->y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
        step.y = TILE_SIZE;
    }
    else                                    // up check
    {
        intercept.y = floor(p_pos->y / TILE_SIZE) * TILE_SIZE - 0.0001;
        step.y = -TILE_SIZE;
    }
    
    // >>> find the (x-coord) for the first horizontal intersection
    intercept.x = p_pos->x + (intercept.y - p_pos->y) / slope;
    step.x = step.y / slope;
    // -----------------------

    // last check
    hor_hit->y = intercept.y;
    hor_hit->x = intercept.x;
    while (true)
    {
        if (!is_wall(game, hor_hit->x, hor_hit->y))
        {
            hor_hit->y += step.y;
            hor_hit->x += step.x;
        }
        else
        {
            game->cast_data.hit_hor = true;
            break ;
        }
    }
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
    int     column;
    double  ray_angle;
	
    column = 0;
    // >>> that ray_angle is the angle of the first ray will start from (left-most)
    ray_angle = game->player.angle - (game->player.fov / 2);    // "DONE"

    while (column < game->cast_data.ray_nbr)
    {
        get_horizontal_intersection(game, ray_angle);

        // >>> get the next angle for the next ray
        ray_angle += game->cast_data.angle_step;
        column++;
    }
}
