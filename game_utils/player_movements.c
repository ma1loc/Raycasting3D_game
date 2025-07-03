# include "cub3D.h"

// >>> wall colision later on will be DONE

int	is_wall(t_game *game, double x, double y)
{
	int	map_x, map_y;

	// Convert world coordinates to map coordinates
	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);
	
	// Check bounds
	if (map_x < 0 || map_x >= game->width || 
		map_y < 0 || map_y >= game->map_height)
		return (1); // Out of bounds = wall
	
	// Check if it's a wall
	if (game->map[map_y][map_x] == '1')
		return (1);
	
	return (0);
}

int	check_collision(t_game *game, double new_x, double new_y)
{
	double	player_radius;
	
	player_radius = (TILE_SIZE / 2) * 0.3; // Smaller collision box
	
	// Check all corners of the player's collision box
	if (is_wall(game, new_x - player_radius, new_y - player_radius) ||
		is_wall(game, new_x + player_radius, new_y - player_radius) ||
		is_wall(game, new_x - player_radius, new_y + player_radius) ||
		is_wall(game, new_x + player_radius, new_y + player_radius))
		return (1);
	
	return (0);
}

// "DONE"
void	upgrade_player_dir(t_game *game, int dir, bool strafe)
{
	t_player_x_y	new_pp;
	double			move_step;

	if (strafe)
		move_step = game->player.angle + (dir * M_PI / 2);
	else
		move_step = game->player.angle;
	
	new_pp.p_x = game->player.pos.p_x + cos(move_step) * MOVE_SPEED;
	new_pp.p_y = game->player.pos.p_y + sin(move_step) * MOVE_SPEED;

	// Check collision before moving
	if (!check_collision(game, new_pp.p_x, new_pp.p_y))
	{
		game->player.pos.p_x = new_pp.p_x;
		game->player.pos.p_y = new_pp.p_y;
	}
}

// // "DONE"
// void	upgrade_player_s_dir(t_game *game, double angle)
// {
// 	double 	new_angle;

// 	new_angle = game->player.angle + angle;
// 	if (fabs(new_angle) > (M_PI * 2))
// 		new_angle = 0;
// 	game->player.angle = new_angle;
// }
