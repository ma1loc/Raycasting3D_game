# include "cub3D.h"

game_exit(int exit_nbr, char *msg)
{
	if (g_game()->game->window->mlx_ptr)
	{
		// distroy the images
		// distroy the window
		// free the mlx_ptr
	}
	exit(exit_nbr);
}


int	key_press(int key_code)
{
	t_direction	*dir;

	dir = g_game()->direction;
	if (key_code == ESC_KEY)
		exit(EXIT_FAILURE);
		// game_exit(exit_nbr);
	
	if (key_code == UP_KEY)
		dir->walk_dir = 1;
	if (key_code == DOWN_KEY)
		dir->walk_dir = -1;
	if (key_code == LEFT_KEY)
		dir->side_dir = -1;
	if (key_code == RIGHT_KEY)
		dir->side_dir = 1;
	if (key_code == LEFT_ARROW)
		dir->turn_dir = -1;
	if (key_code == RIGHT_ARROW)
		dir->turn_dir = 1;
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

// HERE: puting a func to move the player we a key pressed
void	handel_key_press()
{
	t_game	*game;
	t_direction	*dir;

	game = g_game();
	dir = game->direction;
	
	if (dir->walk_dir != 0 || dir->side_dir != 0 || dir->turn_dir != 0)
	{

	}


}
