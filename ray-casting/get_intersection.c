# include "cub3D.h"


void    get_closest_distance(
    t_game *game, t_coord horizontal, t_coord vertical)
{
    t_coord p_pos;
    double  horizontal_dist;
    double  vertical_dist;

    p_pos = game->player.p_pos;

    horizontal_dist = get_distance(p_pos, horizontal);
    vertical_dist = get_distance(p_pos, vertical);
    if (horizontal_dist < vertical_dist)
    {
        game->cast_data.horizontal_hit = true;
        game->cast_data.wall_dist = horizontal_dist;
    }
    else
    {
        game->cast_data.horizontal_hit = false;
        game->cast_data.wall_dist = vertical_dist;
    }
}
