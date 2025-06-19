# include "cub3d.h"

int	key_event(int key_code, t_setup *setup)
{
	t_player	*player;

	player = setup->player;
	(void)player;
	(void)(key_code);
	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(1), 0);
	else if (key_code == UP_KEY)
		player->p_y -= 1;
	else if (key_code == DOWN_KEY)
		player->p_y += 1;
	else if (key_code == LEFT_KEY)
		player->p_x -= 1;
	else if (key_code == RIGHT_KEY)
		player->p_x += 1;
		
	// mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
	// draw_map(setup->game);
	// draw_player_dot(setup->player, setup->game);
	
	return (0);
}
