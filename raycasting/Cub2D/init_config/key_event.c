# include "cub2d.h"

int	key_event(int key_code, t_setup *setup)
{
	(void)setup;
	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(1), 0);
	// else if (key_code == UP_KEY)
	// else if (key_code == DOWN_KEY)
	// else if (key_code == LEFT_KEY)
	// else if (key_code == RIGHT_KEY)
	
	return (0);
}