# include "cub3D.h"

// North(up), South(down), East(right), and West(left).

// void	init_north_dir(t_player *player, int row, int col)
void	init_north_dir(t_player *player)
{
	printf("get the North player position\n");
	player->rot_angle = degrees_to_radians(270);

	player->p_y = row + 0.5; 
	player->p_x = col + 0.5;

	player->dir_x = 0;
	player->dir_y = -1;
}

// void	init_south_dir(t_player *player, int row, int col)
void	init_south_dir(t_player *player)
{
	printf("get the South player position\n");
	player->rot_angle = degrees_to_radians(90);

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 0;
	player->dir_y = 1;
}

// void	init_east_dir(t_player *player, int row, int col)
void	init_east_dir(t_player *player)
{
	printf("get the East player position\n");
	player->rot_angle = degrees_to_radians(0);

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 1;
	player->dir_y = 0;
}

// void	init_west_dir(t_player *player, int row, int col)
void	init_west_dir(t_player *player)
{
	printf("get the West player position\n");
	player->rot_angle = degrees_to_radians(180);

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = -1;
	player->dir_y = 0;
}

void	set_player_direction(t_player *player, t_game *game)
{
	if (game == 'N')
		init_north_position(player);
	else if (game == 'S')
			init_south_position(player);
	else if (game == 'E')
		init_east_position(player);
	else if (game == 'W')
		init_west_position(player);
}
