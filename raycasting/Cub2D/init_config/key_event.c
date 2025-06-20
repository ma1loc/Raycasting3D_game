# include "cub3d.h"

// i don't have any idea about how to get this into the moveing of the player
// double	angle; // >>> player angle in radians
// double	move_speed; // >>> player speed in the map movements, player->move_speed = 0.05
// double	rot_speed;	// >>> rotat left and right

// here i have to get is the new press key hit the wall or not to move the player a bit
int	is_wall(t_setup *setup, int key_code)
{
	if (setup->game->map[(int)setup->direction->new_p_x][(int)setup->direction->new_p_x] == "1")
	{
		//  i think i have to return the new_px/y to the defult if it wall, right?
		direction->new_p_x = player->p_x;
		direction->new_p_y = player->p_y;
		return (1);
	}
	else if (key_code == UP_KEY)
		setup->player->p_y = direction->new_p_y;
	
	else if (key_code == DOWN_KEY)
		setup->player->p_y = direction->new_p_y;
	
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// move the FOV to left
	else if (key_code == LEFT_KEY)
		setup->player->p_x = direction->new_p_x;
	// move the FOV to right
	else if (key_code == RIGHT_KEY)
		setup->player->p_x = direction->new_p_x;
}


int	key_event(int key_code, t_setup *setup)
{
	t_direction	*direction;

	direction = setup->direction;
	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(1), 0);
	
	// player->p_y -= 0.1;
	else if (key_code == UP_KEY)
		direction->new_p_y -= 0.1;
	
	// player->p_y += 0.1;
	else if (key_code == DOWN_KEY)
		direction->new_p_y += 0.1;
	
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// move the FOV to left
	else if (key_code == LEFT_KEY)
		direction->new_p_x -= 0.1;
	// move the FOV to right
	else if (key_code == RIGHT_KEY)
		direction->new_p_x += 0.1;

	if (is_wall(setup, int key_code));
		return (0);

	mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
	draw_top_view_map(setup->game, setup->player);
	draw_player_dot(setup->player, setup->game);
	
	return (0);
}
