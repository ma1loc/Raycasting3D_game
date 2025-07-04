# include "cub3D.h"

// "DONE"
double	degrees_to_radians(int degree)
{
	return (degree * M_PI / 180);
}

// >>> wall colision later on will be DONE
int	is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int map_y;

	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);

	if (map_x < 0 || map_x >= SCREEN_WIDTH || 
		map_y < 0 || map_y >= SCREEN_HEIGHT)
		return (1);
	
	if (game->map[map_y][map_x] == '1')
		return (1);
	
	return (0);
}

int	check_collision(t_game *game, double new_x, double new_y)
{
	double	player_radius;
	
	player_radius = 9;
	if (is_wall(game, new_x - player_radius, new_y - player_radius) ||
		is_wall(game, new_x + player_radius, new_y - player_radius) ||
		is_wall(game, new_x - player_radius, new_y + player_radius) ||
		is_wall(game, new_x + player_radius, new_y + player_radius))
		return (1);

	return (0);
}

// "N_DONE"
void	upgrade_player_dir(t_game *game, int dir, bool strafe)
{
	t_coord		new_pp;
	double		move_step;

	if (strafe)
		move_step = game->player.angle + (dir * M_PI / 2);
	else
		move_step = (game->player.angle);
	// the up and down is working correctly intel i strafe the playe 
	// the up and down key not behave like it be.

	new_pp.x = game->player.p_pos.x + cos(move_step) * MOVE_SPEED;
	new_pp.y = game->player.p_pos.y + sin(move_step) * MOVE_SPEED;

	if (!check_collision(game, new_pp.x, new_pp.y))
	{
		game->player.p_pos.x = new_pp.x;
		game->player.p_pos.y = new_pp.y;
	}
}

// // "DONE"
void	upgrade_player_s_dir(t_game *game, double angle)
{
	double 	new_angle;

	new_angle = game->player.angle + angle;
	if (fabs(new_angle) > (M_PI * 2))
		new_angle = 0;
	game->player.angle = new_angle;
}
