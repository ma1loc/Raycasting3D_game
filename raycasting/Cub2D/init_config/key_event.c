# include "cub3d.h"

// int	pressed_key(t_setup *setup)
// {
	
// }

int	key_event(int key_code, t_setup *setup)
{
	t_player	*player;

	player = setup->player;
	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(1), 0);
	
	else if (key_code == UP_KEY)
		player->p_y -= 0.1;

	else if (key_code == DOWN_KEY)
		player->p_y += 0.1;

	// else if (key_code == LEFT_KEY)
	// 		move the FOV to left
	// else if (key_code == RIGHT_KEY)
	//		move the FOV to right
	
	mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
	draw_top_view_map(setup->game, setup->player);
	draw_player_dot(setup->player, setup->game);
	
	return (0);
}
