# include "cub3d.h"

// >>> as the name of the function converting from degrees to radians
double	degrees_to_radians(int degree)
{
	double	radian;

	// >>> to get the radian we use the one PI (180 degree) 
	// >> becouse the radian based on the PI that's why * 180
	radian = degree * M_PI / 180.0;
	return (radian);
}

void	init_player_config(t_setup *setup)
{
	t_player	*player;
	t_direction	*dir;

	player = setup->player;
	dir = setup->direction;
	player->move_speed = MOVE_SPEED;	// >>> speed of up and down move
	player->rot_speed = ROT_SPEED;		// >>> speed of left/right move 
	dir->turn_dir = 0;					// >>> left -1 and right +1
	dir->walk_dir = 0;					// >>> up -1 and down +1
	get_player_position(setup->player, setup->game);

}
