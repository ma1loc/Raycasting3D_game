# include "cub2d.h"

// simple 2D map first
// second 3D projection
// North(up), South(down), East(right), and West(left).

char	**map_init()
{
	static char map[5][7];
	char **map_ptrs;
	int i;

	const char *default_map[] = {
		"111111",
		"100001",
		"101001",
		"1100N1",
		"111111"
	};
	i = -1;

	while (++i < 5)
		strcpy(map[i], default_map[i]);
	
	map_ptrs = malloc(5 * sizeof(char *));
	i = -1;
	while (++i < 5)
		map_ptrs[i] = map[i];

	return (map_ptrs);
}

void	open_window(t_setup *setup)
{
	// >>> screen width and height, just in case for later use
	int your_screen_width;
	int your_screen_height;

	setup->game->screen_width = 640;
	setup->game->screen_height = 480;
	
	mlx_get_screen_size(setup->game->mlx_ptr, &your_screen_width, &your_screen_height);	
	if (setup->game->screen_width > your_screen_width)
		setup->game->screen_width = your_screen_width;
	if (setup->game->screen_height > your_screen_height)
		setup->game->screen_height = your_screen_height;
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	setup->game->win_ptr = mlx_new_window(setup->game->mlx_ptr, setup->game->screen_width, setup->game->screen_height, "Cub2D");
	if (!setup->game->mlx_ptr || !setup->game->win_ptr)
	{
		perror("Failed to create MLX window");
		free(setup->game);
		free(setup);
		exit(EXIT_FAILURE);
	}
}
// void	set_direction(t_player *player, char dir);
void	get_player_position(t_setup *setup)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (setup->game->map[++i])
	{
		j = 0;
		while (setup->game->map[i][j])
		{
			if (setup->game->map[i][j] == 'N')
			{
				// [i] is the (row)(Y) and [j] is the (column)(X) in the map
				setup->player->p_y = i + 0.5; // Player's Y position
				setup->player->p_x = j + 0.5; // Player's X position
				// setup->player->dir_x = 0; // North direction
				// setup->player->dir_y = -1; // North direction
				// setup->player->plane_x = 0.66; // Camera plane X
				// setup->player->plane_y = 0; // Camera plane Y
			}
			else if (setup->game->map[i][j] == 'S')
			{
				
				setup->player->p_y = i + 0.5;
				setup->player->p_x = j + 0.5;
				// setup->player->dir_x = 0; // South direction
				// setup->player->dir_y = 1; // South direction
				// setup->player->plane_x = -0.66; // Camera plane X
				// setup->player->plane_y = 0; // Camera plane Y
			}
			else if (setup->game->map[i][j] == 'E')
			{
				setup->player->p_y = i + 0.5;
				setup->player->p_x = j + 0.5;
				// setup->player->dir_x = 1; // East direction
				// setup->player->dir_y = 0; // East direction
				// setup->player->plane_x = 0; // Camera plane X
				// setup->player->plane_y = -0.66; // Camera plane Y
			}
			else if (setup->game->map[i][j] == 'W')
			{
				setup->player->p_y = i + 0.5;
				setup->player->p_x = j + 0.5;
				// setup->player->dir_x = -1; // West direction
				// setup->player->dir_y = 0; // West direction
				// setup->player->plane_x = 0; // Camera plane X
				// setup->player->plane_y = 0.66; // Camera plane Y
			}
			j++;
		}
	}
}

int	main()
{
	t_setup *setup;

	// rand();
	// >>> alocate memory for the setup structure
	setup = malloc(sizeof(t_setup));
	if (!setup)
	{
		perror("Failed to allocate memory for setup");
		return (1);
	}
	
	// >>> first thing first, init the game structure
	setup->game = malloc(sizeof(t_game));
	if (!setup->game)
	{
		perror("Failed to allocate memory for game");
		free(setup);
		return (1);
	}
	
	// >>> init the map
	setup->game->map = map_init();


	// >>> Initialize MLX first before using any MLX function
	// >>> you must create a session and get the session pointer (mlx_ptr hold it) first
	setup->game->mlx_ptr = mlx_init();
	
	// >>> open the window and check the resolution of the screen
	open_window(setup);
	
	// >>> keep the session alive and display the window without closing it
	mlx_loop(setup->game->mlx_ptr);

	return (0);
}
