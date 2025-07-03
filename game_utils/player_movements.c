# include "cub3D.h"

// >>> wall colision later on will be DONE

// "DONE"
void	upgrade_player_dir(t_game *game, int dir, bool strafe)
{
	t_player_x_y	new_pp;
	double			move_step;

	if (strafe)
		move_step = game->player.angle + (dir * M_PI / 2);
	else
		move_step = game->player.angle;
	new_pp.p_x = game->player.pos.p_x + cos(move_step) * MOVE_SPEED;
	new_pp.p_y = game->player.pos.p_y + sin(move_step) * MOVE_SPEED;

    // >>>> HERE: check if the new position is valid, later on
    game->player.pos.p_x = new_pp.p_x;
    game->player.pos.p_y = new_pp.p_y;

}

// "DONE"
void	upgrade_player_s_dir(t_game *game, double angle)
{
	double 	new_angle;

	new_angle = game->player.angle + angle;
	if (fabs(new_angle) > (M_PI * 2))
		new_angle = 0;
	game->player.angle = new_angle;
}
