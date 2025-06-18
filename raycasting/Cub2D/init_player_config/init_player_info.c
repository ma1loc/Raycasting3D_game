# include "cub2d.h"



void	init_player_config(t_setup *setup)
{
	// (void)setup;
	t_player *player;

	player = setup->player;

	// >>> first thing first i have to give it the angle (FOV)
	// >>> before that i have to create an way that convete degree to radians
	player->angle = degrees_to_radians(60);	// >>> FOV of the player
	player->move_speed = 0.05;	// >>> speed of up and down move
	player->rot_speed = 0.05;	// >>> speed of left/right move 

	get_player_position(setup); // here segv
}