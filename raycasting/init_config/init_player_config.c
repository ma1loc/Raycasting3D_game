# include "cub3D.h"

double	degrees_to_radians(int degree)
{
	double	radian;

	radian = degree * M_PI / 180.0;
	return (radian);
}

void	init_player_direction(t_setup *setup)
{
	t_player	*player;
	t_direction	*dir;

	player = setup->player;
	dir = setup->direction;

	player->move_speed = MOVE_SPEED;
	player->rot_speed = ROT_SPEED;
	dir->turn_dir = 0;
	dir->walk_dir = 0;
	dir->side_dir = 0;

	// >>> to set
	set_player_direction(player, setup->game);
}
