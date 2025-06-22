# include "cub3d.h"

// i don't have any idea about how to get this into the moveing of the player
// double	angle; // >>> player angle in radians
// double	move_speed; // >>> player speed in the map movements, player->move_speed = 0.05
// double	rot_speed;	// >>> rotat left and right

// here i have to get is the new press key hit the wall or not to move the player a bit
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
	
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// move the FOV to left
	// move the FOV to right
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
		setup->player->p_x = direction->new_p_x;

	return (0);
}

int	key_event(int key_code, t_setup *setup)
{
	t_direction	*dir;
	t_player	*player;
	
	
	dir = setup->direction;
	player = setup->player;
	dir->new_p_x = player->p_x;
	dir->new_p_y = player->p_y;

	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(0), 0);

	// move the player up/down
	if (key_code == UP_KEY)
		dir->new_p_y -= 0.2;
	else if (key_code == DOWN_KEY)
		dir->new_p_y += 0.2;
	// rotate the player left/right
	// to fix -> i have to get this in the right direction
	else if (key_code == LEFT_KEY)
		dir->new_p_x -= 0.2;
	else if (key_code == RIGHT_KEY)
		dir->new_p_x += 0.2;

	if (is_wall(setup, key_code))
		return (0);

	mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
	draw_top_view_map(setup->game, setup->player);
	draw_player_dot(setup->player, setup->game);

	return (0);
}
