# include "../srcs/cub3D.h"

// int	is_wall_at(t_setup *setup, double x, double y)
// {
// 	int	map_x;
// 	int	map_y;

// 	map_x = (int)x;
// 	map_y = (int)y;
	
// 	if (map_x < 0 || map_y < 0)
// 		return (1);
	
// 	if (!setup->game->map[map_y])
// 		return (1);
	
// 	if (map_x >= (int)strlen(setup->game->map[map_y]))
// 		return (1);
	
// 	if (setup->game->map[map_y][map_x] == '1')
// 	{
// 		printf("hit the wall at | y->%d | x->%d |\n", map_y, map_x);
// 		return (1);
// 	}
// 	return (0);
// }

// int	is_valid_move(t_setup *setup, double new_x, double new_y)
// {
// 	double	buffer = 0.005;
// 	// double	buffer = 0;
	
// 	if (is_wall_at(setup, new_x - buffer, new_y - buffer) ||
// 		is_wall_at(setup, new_x + buffer, new_y - buffer) ||
// 		is_wall_at(setup, new_x - buffer, new_y + buffer) ||
// 		is_wall_at(setup, new_x + buffer, new_y + buffer))
// 		return (0);
	
// 	return (1);
// }
