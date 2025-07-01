# include "cub3D.h"

int	key_press(int key_code)
{
	t_direction	*dir;

	dir = g_game()->direction;
	if (key_code == ESC_KEY)
		exit(EXIT_FAILURE);
	
	if (key_code == UP_KEY)
		dir->walk_dir = FORWARD;
	if (key_code == DOWN_KEY)
		dir->walk_dir = BACKWARD;
	if (key_code == LEFT_KEY)
		dir->side_dir = LEFT;
	if (key_code == RIGHT_KEY)
		dir->side_dir = RIGHT;
	if (key_code == LEFT_ARROW)
		dir->turn_dir = TURN_LEFT;
	if (key_code == RIGHT_ARROW)
		dir->turn_dir = TURN_RIGHT;
	return (0);
}

int	key_release(int key_code)
{
	t_direction	*dir;

	dir = g_game()->direction;
	if (key_code == UP_KEY || key_code == DOWN_KEY)
		dir->walk_dir = 0;
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
		dir->side_dir = 0;
	else if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		dir->turn_dir = 0;
	return (0);
}

void	upgrade_player_dir(t_game *game, int dir, bool strafe)
{
	t_player_x_y	new_pp;
	double			move_step;

	if (strafe)
		move_step = game->player->angle + (dir * M_PI / 2);
	else
		move_step = game->player->angle;
	new_pp.p_x = game->player->pos.p_x + sin(move_step) * MOVE_SPEED;
	new_pp.p_y = game->player->pos.p_y + cos(move_step)	* MOVE_SPEED;
	// >>>> HERE: check if the new position is valid
}

upgrade_player_s_dir(t_game *game, double angle)
{
	double 	new_angle;

	new_angle = game->player->angle + angle;
	if (fabs(new_angle) > (M_PI * 2))
		new_angle = 0;
	game->player->angle = new_angle;
}

void	handle_key_press()
{
    t_game		*game;
    t_direction	*dir;

    game = g_game();
    dir = game->direction;
    if (dir->walk_dir == FORWARD)
        upgrade_player_dir(game, FORWARD, false);
    if (dir->walk_dir == BACKWARD)
        upgrade_player_dir(game, BACKWARD, false);
    if (dir->side_dir == LEFT)
        upgrade_player_dir(game, LEFT, true);
    if (dir->side_dir == RIGHT)
        upgrade_player_dir(game, RIGHT, true);

    if (dir->turn_dir == TURN_LEFT)
        upgrade_player_s_dir(game, -ROT_SPEED);
    if (dir->turn_dir == TURN_RIGHT)
        upgrade_player_s_dir(game, ROT_SPEED);
}
