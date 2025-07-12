# include "cub3D.h"

void	get_map_size(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
		y++;
	game->cast_data.map_y = y;
	game->cast_data.map_x = ft_strlen(game->map[0]);
}

// this function normalize the ray_angle when is nigative
// rotat it to (PI * 2)
double	normalize_angle(double angle)
{
    double new_angle;

    new_angle = fmod(angle, 2 * M_PI);
    if (new_angle < 0)
        new_angle += 2 * M_PI;
    return (new_angle);
}
