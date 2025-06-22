# include "cub3d.h"

// >>> as the name of the function converting from degrees to radians
double	degrees_to_radians(int degree)
{
	double	radian;

	// to get the radian we use the one PI (180 degree) 
	// becouse the radian based on the PI that's why * 180
	radian = degree * M_PI / 180.0;
	return (radian);
}


void	get_player_angle(t_player *player)
{
	if (ANGEL == 'N')
		player->angle = degrees_to_radians(90);
	else if (ANGEL == 'S')
		player->angle = degrees_to_radians(270);
	else if (ANGEL == 'E')
		player->angle = degrees_to_radians(360);
	else if (ANGEL == 'W')
		player->angle = degrees_to_radians(180);
}

void	init_player_config(t_setup *setup)
{
	t_player *player;

	player = setup->player;
	// seting shit setup here

	// >>> first thing first i have to give it the angle (FOV)
	// >>> before that i have to create an way that convete degree to radians

	get_player_angle(player);
	player->move_speed = MOVE_SPEED;	// >>> speed of up and down move
	player->rot_speed = ROT_SPEED;		// >>> speed of left/right move 

	// init the new row/col
	setup->direction->new_p_y = player->p_y;
	setup->direction->new_p_x = player->p_x;

	get_player_position(setup->player, setup->game);

}
