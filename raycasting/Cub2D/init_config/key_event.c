# include "cub3d.h"

// i don't have any idea about how to get this into the moveing of the player
// double	angle; // >>> player angle in radians
// double	move_speed; // >>> player speed in the map movements, player->move_speed = 0.05
// double	rot_speed;	// >>> rotat left and right

// here i have to get is the new press key hit the wall or not to move the player a bit

// LEFT / RIGHT → change rot_angle
// UP / DOWN → use cos(rot_angle) and sin(rot_angle) for new positions
// new_p_x = player->p_x + cos(player->rot_angle) * walk_dir * speed;
// new_p_y = player->p_y + sin(player->rot_angle) * walk_dir * speed;

// int	is_wall(t_setup *setup, int key_code)
// {
// 	t_direction	*direction;
// 	t_player	*player;
// 	double		radius;
// 	double 		x;
// 	double		y;
	
// 	radius = 4 / TILE_SIZE;
// 	player = setup->player;
// 	direction = setup->direction;
// 	x = direction->new_p_x;
// 	y = direction->new_p_y;

// 	if (setup->game->map[(int)(y - radius)][(int)(x - radius)] == '1' ||
// 		setup->game->map[(int)(y - radius)][(int)(x + radius)] == '1' ||
// 		setup->game->map[(int)(y + radius)][(int)(x - radius)] == '1' ||
// 		setup->game->map[(int)(y + radius)][(int)(x + radius)] == '1')
// 	{
// 		direction->new_p_x = player->p_x;
// 		direction->new_p_y = player->p_y;
// 		return (1);
// 	}
// 	else if (key_code == UP_KEY || key_code == DOWN_KEY)
// 		setup->player->p_y = direction->new_p_y;
	
// 	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
// 		setup->player->p_x = direction->new_p_x;

// 	return (0);
// }

void	reset_direction(t_direction *dir)
{
	dir->turn_dir = 0;
	dir->turn_dir = 0;
}

int	key_event(int key_code, t_setup *setup)
{
	t_player	*player;
	t_direction	*dir;
	
	
	player = setup->player;
	dir = setup->direction;
	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(0), 0);

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	// move the player up/down
	if (key_code == UP_KEY)
		dir->walk_dir = -1;
	else if (key_code == DOWN_KEY)
		dir->walk_dir = 1;
	else if (key_code == LEFT_KEY)
		dir->turn_dir = -1;
	else if (key_code == RIGHT_KEY)
		dir->turn_dir = 1;

	// if (is_wall(setup, key_code))
	// 	return (0);
	
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
	draw_top_view_map(setup->game, setup->player);
	draw_player_dot(setup->player, setup->game);
	reset_direction(setup->direction); 
	printf(">>> DONE reset the key direction\n");
	return (0);
}
