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


// void	set_direction(t_player *player, char dir);
void	get_player_position(t_setup *setup)
{
	int	i;
	int	j;

	i = 0;
	while (setup->game->map[i])
	{
		// j = -1;
		j = 0;
		while (setup->game->map[i][j])
		{
			// [i] is the (row)(Y) and [j] is the (column)(X) in the map
			setup->player->p_y = i + 0.5; // Player's Y position
			setup->player->p_x = j + 0.5; // Player's X position
			if (setup->game->map[i][j] == 'N')
			{
				printf("get the North player position\n");

				setup->player->dir_x = 0;	// >>> for the row
				setup->player->dir_y = -1;	// >>> for the colum

				// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
				// setup->player->plane_x = 0.66; // Camera plane X
				// setup->player->plane_y = 0; // Camera plane Y
				// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

			}
			else if (setup->game->map[i][j] == 'S')
			{
				printf("get the South player position\n");

				setup->player->dir_x = 0; // South direction
				setup->player->dir_y = 1; // South direction

				// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
				// setup->player->plane_x = -0.66; // Camera plane X
				// setup->player->plane_y = 0; // Camera plane Y
				// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			}
			else if (setup->game->map[i][j] == 'E')
			{
				printf("get the East player position\n");

				setup->player->dir_x = 1; // East direction
				setup->player->dir_y = 0; // East direction

				// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
				// setup->player->plane_x = 0; // Camera plane X
				// setup->player->plane_y = -0.66; // Camera plane Y
				// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

			}
			else if (setup->game->map[i][j] == 'W')
			{
				printf("get the West player position\n");

				setup->player->dir_x = -1; // West direction
				setup->player->dir_y = 0; // West direction

				// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
				// setup->player->plane_x = 0; // Camera plane X
				// setup->player->plane_y = 0.66; // Camera plane Y
				// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

			}
			j++;
		}
		i++;
	}
}

// >>> as the name of the function converting from degrees to radians
double	degrees_to_radians(int degree)
{
	double	radian;

	// to get the radian we use the one PI (180 degree) 
	// becouse the radian based on the PI that's why * 180
	radian = degree * M_PI / 180.0;
	return (radian);
}

// void	init_player_config(t_setup *setup)
// {
// 	// (void)setup;
// 	t_player *player;

// 	player = setup->player;

// 	// >>> first thing first i have to give it the angle (FOV)
// 	// >>> before that i have to create an way that convete degree to radians
// 	player->angle = degrees_to_radians(60);	// >>> FOV of the player
// 	player->move_speed = 0.05;	// >>> speed of up and down move
// 	player->rot_speed = 0.05;	// >>> speed of left/right move 

// 	get_player_position(setup); // here segv

// }

int	key_event(int key_code, t_setup *setup)
{
	(void)setup;
	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(1), 0);
	// else if (key_code == UP_KEY)
	// else if (key_code == DOWN_KEY)
	// else if (key_code == LEFT_KEY)
	// else if (key_code == RIGHT_KEY)
	
	return (0);
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
		return (1);
	}
	setup->player = malloc(sizeof(t_player));
	if (!setup->player)
	{
		perror("Failed to allocate memory for game");
		return (1);
	}

	
	// >>> init the map
	setup->game->map = map_init();

	// >>> Initialize MLX first before using any MLX function
	// >>> you must create a session and get the session pointer (mlx_ptr hold it) first
	setup->game->mlx_ptr = mlx_init();
	
	// >>> open the window and check the resolution of the screen
	open_window(setup);
	
	init_player_config(setup);	// >>> segv here to fix
	
	// >>> lession on the key event
	mlx_key_hook(setup->game->win_ptr, key_event, &setup);

	// >>> keep the session alive and display the window without closing it
	mlx_loop(setup->game->mlx_ptr);

	return (0);
}
