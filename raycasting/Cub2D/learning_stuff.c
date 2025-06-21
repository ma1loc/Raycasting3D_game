# include "cub3d.h"

int	is_wall(t_setup *setup, int key_code)
{
	t_direction	*dir = setup->direction;
	t_player	*player = setup->player;

	if (setup->game->map[(int)dir->new_p_y][(int)dir->new_p_x] == '1')
	{
		dir->new_p_x = player->p_x;
		dir->new_p_y = player->p_y;
		return (1);
	}

	if (key_code == UP_KEY || key_code == DOWN_KEY)
		player->p_y = dir->new_p_y;
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
		player->p_x = dir->new_p_x;

	return (0);
}

int	key_event(int key_code, t_setup *setup)
{
	t_direction	*dir = setup->direction;
	t_player	*player = setup->player;

	dir->new_p_x = player->p_x;
	dir->new_p_y = player->p_y;

	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(0), 0);

	if (key_code == UP_KEY)
		dir->new_p_y -= 0.1;
	else if (key_code == DOWN_KEY)
		dir->new_p_y += 0.1;
	else if (key_code == LEFT_KEY)
		dir->new_p_x -= 0.1;
	else if (key_code == RIGHT_KEY)
		dir->new_p_x += 0.1;

	if (is_wall(setup, key_code))
		return (0);

	mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
	draw_top_view_map(setup->game, setup->player);
	draw_player_dot(setup->player, setup->game);

	return (0);
}


double radius = 4.0 / TILE_SIZE;
double x = direction->new_p_x;
double y = direction->new_p_y;

if (
    setup->game->map[(int)(y - radius)][(int)(x - radius)] == '1' ||
    setup->game->map[(int)(y - radius)][(int)(x + radius)] == '1' ||
    setup->game->map[(int)(y + radius)][(int)(x - radius)] == '1' ||
    setup->game->map[(int)(y + radius)][(int)(x + radius)] == '1'
)
{
    direction->new_p_x = player->p_x;
    direction->new_p_y = player->p_y;
    return (1);
}
