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

// void	walk_dir(t_setup *setup, int *move);

void	re_drow(t_setup *setup, int *moved)
{
   	if (*moved)
    {
        mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
        draw_top_view_map(setup->game, setup->player);
        draw_player_dot(setup->player, setup->game);
    }
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

void	update_walk_dir(t_setup *setup, int *moved)
{
	t_player *player;
	double move_step;
	double	new_p_x;
	double	new_p_y;

	player = setup->player;
	move_step = setup->direction->walk_dir * player->move_speed;
    new_p_x = player->p_x + cos(player->rot_angle) * move_step;
    new_p_y = player->p_y + sin(player->rot_angle) * move_step;        
    if (is_valid_move(setup, new_p_x, new_p_y))
    {
        player->p_x = new_p_x;
        player->p_y = new_p_y;
        *moved = 1;
    }
	else	// wall collision
		wall_collision(setup, new_p_x, new_p_y, moved);

}

int game_loop(t_setup *setup)
{
    t_direction *dir;
    t_player    *player;
	
    int         moved;
    dir = setup->direction;
    player = setup->player;
    moved = 0;

    if (dir->walk_dir != 0)
		update_walk_dir(setup, &moved);


    if (dir->turn_dir != 0)
    {
        player->rot_angle += dir->turn_dir * player->rot_speed;
        moved = 1;
    }

	re_drow(setup, &moved);
    return (0);
}

int	key_event(int key_code, t_setup *setup)
{
	t_direction	*dir;

	dir = setup->direction;
	if (key_code == ESC_KEY)
		exit(EXIT_SUCCESS);
	else if (key_code == UP_KEY)
		dir->walk_dir = 1;
	else if (key_code == DOWN_KEY)
		dir->walk_dir = -1;
	else if (key_code == LEFT_KEY)
		dir->turn_dir = -1;
	else if (key_code == RIGHT_KEY)
		dir->turn_dir = 1;
	if (dir->walk_dir != 0 || dir->turn_dir != 0)
		game_loop(setup);
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
