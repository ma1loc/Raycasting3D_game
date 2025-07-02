# include "cub3D.h"

double	degrees_to_radians(int degree)
{
	double	radian;

	radian = degree * M_PI / 180.0;
	return (radian);
}

void	init_dir(double angle)
{
	t_game	*game;

	game = g_game();
	game->player->fov = degrees_to_radians(FOV);
	game->player.angle = degrees_to_radians(angle);
	game->player->pos.p_x = game->player_pos.height;
	game->player->pos.p_y = game->player_pos.width;
}

void	set_player_dir()
{
	t_game *game;

	game = g_game();
	if (game->player_pos.player == 'N')
		init_dir(270);
	else if (game == 'S')
		init_dir(90);
	else if (game == 'E')
		init_dir(0);
	else if (game == 'W')
		init_dir(180);
}

void	init_player_dir()
{
	t_direction	*dir;

	dir = g_game()->direction;
	dir->turn_dir = 0;
	dir->walk_dir = 0;
	dir->side_dir = 0;

	set_player_dir();
}
