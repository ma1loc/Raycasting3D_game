# include "cub3d.h"

// void	set_direction(t_player *player, char dir);
// North(up), South(down), East(right), and West(left).

void	init_north_position(t_player *player)
{
	printf("get the North player position\n");

	player->dir_x = 0;	// >>> for the row
	player->dir_y = -1;	// >>> for the colum

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = 0.66; // Camera plane X
	// setup->player->plane_y = 0; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

}

void	init_south_position(t_player *player)
{
	printf("get the South player position\n");

	player->dir_x = 0; // South direction
	player->dir_y = 1; // South direction

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = -0.66; // Camera plane X
	// setup->player->plane_y = 0; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

void	init_east_position(t_player *player)
{
	printf("get the East player position\n");

	player->dir_x = 1; // East direction
	player->dir_y = 0; // East direction

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = 0; // Camera plane X
	// setup->player->plane_y = -0.66; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

void	init_west_position(t_player *player)
{
	printf("get the West player position\n");

	player->dir_x = -1; // West direction
	player->dir_y = 0; // West direction

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = 0; // Camera plane X
	// setup->player->plane_y = 0.66; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

}
void	get_player_position(t_player *player, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			// [i] is the (row)(Y) and [j] is the (column)(X) in the map
				if (game->map[i][j] == 'N')
				{
					player->p_y = i + 0.5;
					player->p_x = j + 0.5;
					init_north_position(player);
				}
				else if (game->map[i][j] == 'S')
				{
					player->p_y = i + 0.5;
					player->p_x = j + 0.5;
					init_south_position(player);
				}
				else if (game->map[i][j] == 'E')
				{
					player->p_y = i + 0.5;
					player->p_x = j + 0.5;
					init_east_position(player);
				}
				else if (game->map[i][j] == 'W')
				{
					player->p_y = i + 0.5;
					player->p_x = j + 0.5;
					init_west_position(player);
				}
			j++;
		}
		i++;
	}
}
