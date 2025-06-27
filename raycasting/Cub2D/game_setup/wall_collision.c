# include "cub3d.h"

int	is_wall_at(t_setup *setup, double x, double y)
{
	int map_x = (int)(x);
	int map_y = (int)(y);

	if (x < 0 || y < 0)
		return (1);
	if (!setup->game->map[map_y] || !setup->game->map[map_y][map_x])
		return (1);
	if (setup->game->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	is_valid_move(t_setup *setup, double new_x, double new_y)
{
	double	radius = 0.03;


	if (is_wall_at(setup, new_x + radius, new_y))
		return (0);
	if (is_wall_at(setup, new_x - radius, new_y))
		return (0);
	if (is_wall_at(setup, new_x, new_y + radius))
		return (0);
	if (is_wall_at(setup, new_x, new_y - radius))
		return (0);
	return (1);
}

void	wall_collision(t_setup *setup, double x, double y, int *moved)
{
	t_player *player;

	player = setup->player;
	if (is_valid_move(setup, x, player->p_y))
    {
        player->p_x = x;
        *moved = 1;
    }
    else if (is_valid_move(setup, player->p_x, y))
    {
        player->p_y = y;
        *moved = 1;
    }
}
