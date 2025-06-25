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

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

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

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int	is_wall(t_setup *setup, int key_code)
{
	t_direction	*direction;
	t_player	*player;
	double		radius;
	double 		x;
	double		y;
	
	radius = 4 / TILE_SIZE;
	player = setup->player;
	direction = setup->direction;
	x = direction->new_p_x;
	y = direction->new_p_y;

	if (setup->game->map[(int)(y - radius)][(int)(x - radius)] == '1' ||
		setup->game->map[(int)(y - radius)][(int)(x + radius)] == '1' ||
		setup->game->map[(int)(y + radius)][(int)(x - radius)] == '1' ||
		setup->game->map[(int)(y + radius)][(int)(x + radius)] == '1')
	{
		direction->new_p_x = player->p_x;
		direction->new_p_y = player->p_y;
		return (1);
	}
	else if (key_code == UP_KEY || key_code == DOWN_KEY)
		setup->player->p_y = direction->new_p_y;
	
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
		setup->player->p_x = direction->new_p_x;

	return (0);
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

if (key_code == UP_KEY)	// -1
		player->p_x = cos(player->rot_angle) * dir->walk_dir * player->move_speed;
		player->p_y = sin(player->rot_angle) * dir->walk_dir * player->move_speed;
	else if (key_code == DOWN_KEY)	// +1
		player->p_x = cos(player->rot_angle) * dir->walk_dir * player->move_speed;
		player->p_y = sin(player->rot_angle) * dir->walk_dir * player->move_speed;
// or like this
if (key_code == UP_KEY || key_code == DOWN_KEY)
	player->p_x = cos(player->rot_angle) * dir->walk_dir * player->move_speed;
	player->p_y = sin(player->rot_angle) * dir->walk_dir * player->move_speed;

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



int	game_loop(t_setup *setup)
{
	t_direction	*dir;
	t_player	*player;
	int			moved;

	dir = setup->direction;
	player = setup->player;
	moved = 0;

	if (dir->walk_dir != 0)
	{
		double move_step = dir->walk_dir * player->move_speed;
		double new_p_x = player->p_x + cos(player->rot_angle) * move_step;
		double new_p_y = player->p_y + sin(player->rot_angle) * move_step;

		if (is_valid_move(setup, new_p_x, new_p_y))
		{
			player->p_x = new_p_x;
			player->p_y = new_p_y;
			moved = 1;
		}
	}

	if (dir->turn_dir != 0)
	{
		player->rot_angle += dir->turn_dir * player->rot_speed;
		moved = 1;
	}

	if (moved)
	{
		mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
		draw_top_view_map(setup->game, setup->player);
		draw_player_dot(setup->player, setup->game);
	}
	return (0);
}
