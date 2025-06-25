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

// witche one move left/right
// know the a-axis and the y-axis
// cos(angle) → Horizontal movement (X-axis)
// sin(angle) → Vertical movement (Y-axis)
// virtical move/ herizontal move
// ver move -> p_y -> sin -> row or column ?
// hor move -> p_x -> cos
//  UP/DOWN move the Player vertical Y useing sin why sin not cos?
// i print the p_x that represent the horzental move but no chagne of the value
// that mean's is not for the walk_dir up/down move?
// is i have to create an image buffer of the red player piexl put?

// have to get the wall colision 
int	is_wall(t_setup *setup, int new_p_x, int new_p_y)
{
	double		radius;
	
	radius = 4 / TILE_SIZE;
	if (setup->game->map[(int)(new_p_y - radius)][(int)(new_p_x - radius)] == '1')
		return (1);
	return (0);
}

int	update_pposition(t_setup *setup, int key_code)
{
	t_player	*player;
	t_direction	*dir;
	double		move_step;
	
	player = setup->player;
	dir = setup->direction;
	
	if (key_code == UP_KEY || key_code == DOWN_KEY)
	{
		move_step = dir->walk_dir * player->move_speed;

		// >>> (cos) is moving the player horizontal(p_x)
		double new_p_x = player->p_x + cos(player->rot_angle) * move_step;
		// >>> (sin) is moving the player vertical(p_y)
		double new_p_y = player->p_y + sin(player->rot_angle) * move_step;
 

		if (is_wall(setup, new_p_x, new_p_y))
			return (1);
		player->p_x = new_p_x;
		player->p_y = new_p_y;
		printf("player->p_x %f\n", player->p_x);
		printf("player->p_y %f\n", player->p_y);
	}
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
		player->rot_angle += dir->turn_dir * player->rot_speed;
	return (0);
}

int	key_event(int key_code, t_setup *setup)
{
	t_direction	*dir;

	dir = setup->direction;
	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(0), 0);
	else if (key_code == UP_KEY)
		dir->walk_dir = 1;
	else if (key_code == DOWN_KEY)
		dir->walk_dir = -1;
	else if (key_code == LEFT_KEY)
		dir->turn_dir = -1;
	else if (key_code == RIGHT_KEY)
		dir->turn_dir = 1;
	else
		return (0);	

	update_pposition(setup, key_code);
	
	mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
	draw_top_view_map(setup->game, setup->player);
	draw_player_dot(setup->player, setup->game);
	return (0);
}

int	key_release(int key_code, t_setup *setup)
{
	t_direction	*dir;

	dir = setup->direction;
	if (key_code == UP_KEY || key_code == DOWN_KEY)
		dir->walk_dir = 0;
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
		dir->turn_dir = 0;
	return (0);
}
