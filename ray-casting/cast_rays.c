# include "cub3D.h"

int     is_hit(t_game *game, t_coord intercept)
{
    int map_x;
    int map_y;

	map_x = (int)(intercept.x / TILE_SIZE);
	map_y = (int)(intercept.y / TILE_SIZE);

    if (map_x < 0 || map_x >= game->cast_data.map_x ||
        map_y < 0 || map_y >= game->cast_data.map_y)
        return (1);
    return (game->map[map_y][map_x] == '1');
}

t_intercept_hit	check_intersection_hit(
    t_game *game, t_intercept_hit intercept, t_coord step)
{
    while (true)
    {
        if (is_hit(game, intercept.intercept))
            break;
		intercept.intercept.x += step.x;
        intercept.intercept.y += step.y;
    }
    return (intercept);
}

// ----------- horizontal intersection -----------
t_intercept_hit	get_horizontal_intersection(
	t_game *game, t_coord p_pos, double ray_angle)
{
    double          slope;
    t_intercept_hit intercept;
    t_coord         step;

	(void)game;
    slope = tan(ray_angle);
    if (ray_angle > 0 && ray_angle < M_PI)  // facing down (South)
    {
        intercept.intercept.y = floor(
			p_pos.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
        intercept.inter_dir = South;
        step.y = TILE_SIZE;
    }
    else // facing up (North)
    {
        intercept.intercept.y = floor(
			p_pos.y / TILE_SIZE) * TILE_SIZE - EPS;
        intercept.inter_dir = North;
        step.y = -TILE_SIZE;
    }
    intercept.intercept.x = p_pos.x + (
		intercept.intercept.y - p_pos.y) / slope;
    step.x = step.y / slope;

	return (check_intersection_hit(game, intercept, step));
}

// ----------- vertical intersection -----------
t_intercept_hit get_vertical_intersection(
	t_game *game, t_coord p_pos, double ray_angle)
{
    double          slope;
    t_intercept_hit intercept;
    t_coord         step;

    slope = tan(ray_angle);

    if (ray_angle < M_PI / 2 || ray_angle > (M_PI * 3) / 2)  // facing right (East)
    {
        intercept.intercept.x = floor(
			p_pos.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
        intercept.inter_dir = East;
        step.x = TILE_SIZE;
    }
    else // facing left (West)
    {
        intercept.intercept.x = floor(
			p_pos.x / TILE_SIZE) * TILE_SIZE - EPS;
        intercept.inter_dir = West;
        step.x = -TILE_SIZE;
    }
    intercept.intercept.y = p_pos.y + (
		intercept.intercept.x - p_pos.x) * slope;
    step.y = step.x * slope;

    return (check_intersection_hit(game, intercept, step));
}


// t_intercept_hit cast_ray(t_game *game, double ray_angle)
// {
//     t_intercept_hit	horizontal_hit;
// 	t_intercept_hit vertical_hit;
// 	t_intercept_hit re

//     horizontal_hit = get_horizontal_intersection(
//         game, game->player.p_pos, ray_angle);
//     vertical_hit = get_vertical_intersection(
//         game, game->player.p_pos, ray_angle);
	
    
// 	get_closest_distance(
//         game, horizontal_hit.intercept, vertical_hit.intercept);
    

//     if (game->cast_data.horizontal_hit)
//         horizontal_hit);
// 	else
//     return (vertical_hit);
// }

t_intercept_hit cast_ray(t_game *game, double ray_angle)
{
    t_intercept_hit	horizontal_hit;
    t_intercept_hit vertical_hit;
    t_intercept_hit result;

    horizontal_hit = get_horizontal_intersection(
        game, game->player.p_pos, ray_angle);
    vertical_hit = get_vertical_intersection(
        game, game->player.p_pos, ray_angle);
    
    get_closest_distance(
        game, horizontal_hit.intercept, vertical_hit.intercept);
    
    if (game->cast_data.horizontal_hit)
        result = horizontal_hit;
    else
        result = vertical_hit;
    
    game->cast_data.wall_dist = get_distance(game->player.p_pos, result.intercept);
    
    return (result);
}
