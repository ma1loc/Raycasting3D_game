# include "cub2d.h"

char	**map_init()	// >>> to remove later on
{
	static char map[5][7];
	char **map_ptrs;
	int i;

	const char *default_map[] = {
		"111111",
		"100001",
		"101001",
		"1100N1",
		"111111",
		NULL
	};
	i = 0;
	while (i < 5)
	{
		strcpy(map[i], default_map[i]);
		i++;
	}
	
	map_ptrs = malloc(6 * sizeof(char *));
	i = 0;
	while (i < 5)
	{
		map_ptrs[i] = map[i];
		i++;
	}
	return (map_ptrs);
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// done // for the 3D view used
void	open_window(t_game *game)
{
	// >>> screen width and height, just in case for later use
	int 	full_width;
	int 	full_height;

	game->screen_width = SCREEN_WIDTH;
	game->screen_height = SCREEN_HEIGHT;
	mlx_get_screen_size(game->mlx_ptr, &full_width, &full_height);
	if (SCREEN_WIDTH > full_width)
		game->screen_width = full_width;
	if (SCREEN_HEIGHT > full_height)
		game->screen_height = full_height;

	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_width, game->screen_height, "Cub2D");
	if (!game->win_ptr)
	{
		perror("Failed to create MLX window");
		exit(EXIT_FAILURE);
	}
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void	open_window_2d(t_game *game)
{
	// int	width;
	// int	height;	

	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				printf("get position\n");
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_game_config(t_game *game)
{
	game->mlx_ptr = mlx_init();
	// if (!game->mlx_ptr)
		// >>> later on
	// open_window(game);	// >>> 3D view used
	
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	game->map = map_init();	// >>> the map
	// open_window_2d(game);


}