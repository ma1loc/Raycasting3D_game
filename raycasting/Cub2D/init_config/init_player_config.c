# include "cub2d.h"

// >>> as the name of the function converting from degrees to radians
double	degrees_to_radians(int degree)
{
	double	radian;

	// to get the radian we use the one PI (180 degree) 
	// becouse the radian based on the PI that's why * 180
	radian = degree * M_PI / 180.0;
	return (radian);
}

void	init_player_config(t_player *player, t_game *game)
{
	// >>> first thing first i have to give it the angle (FOV)
	// >>> before that i have to create an way that convete degree to radians
	player->angle = degrees_to_radians(60);	// >>> FOV of the player
	player->move_speed = 0.05;	// >>> speed of up and down move
	player->rot_speed = 0.05;	// >>> speed of left/right move 

	get_player_position(player, game);

}

