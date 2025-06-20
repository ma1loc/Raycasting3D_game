# ifndef CUB3D_H
# define CUB3D_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

// # define GRAY_COLOR 0xAAAAAA
// # define D_GRAY_COLOR 0x222222
#define RED_COLOR 0xFF0000

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1


// the key presed to add
# define UP_KEY    XK_w
# define DOWN_KEY  XK_s
# define LEFT_KEY  XK_a
# define RIGHT_KEY XK_d
# define ESC_KEY   XK_Escape

# define TILE_SIZE 32

// this is just for the 3d view
# define SCREEN_WIDTH 1920
// this is just for the 3d view
# define SCREEN_HEIGHT 1080


// typedef struct s_image
// {
//     void    *img_ptr;
//     char    *data;
//     int     bpp;
//     int     size_line;
//     int     endian;
//     int     width;
//     int     height;
// }   t_image;

typedef struct s_direction
{
	double	new_row;
	double	new_col;
}	t_direction;

typedef struct s_top_view
{
	void	*player_img;
	void	*wall_img;
	void	*free_space_img;
}	t_top_view;

typedef	struct s_player
{
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	double	angle; // >>> player angle in radians
	double	move_speed; // >>> player speed in the map movements, player->move_speed = 0.05
	double	rot_speed;	// >>> rotat left and right
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	// >>> player position in the map(x, y)
	// how to init this at first just loop thghout the map and git it value of int not float
	double	p_x;
	double	p_y;

	// >>> player direction in the map (north, south, east, west)
	double	dir_x;
	double	dir_y;

	/// >>> player camera plane for the (fov)field of view of the player
	double	plane_x;
	double	plane_y;

}	t_player;

typedef struct s_game
{
	void	*mlx_ptr;	// >>> done
	void	*win_ptr;	// >>> done
	char	**map;		// >>> done
	int		map_width;	// >>> done
	int		map_height;	// >>> done
	// for the 3D view
	int		screen_width;	// this is just for the 3d view
	int		screen_height;	// // this is just for the 3d view
	int		tile_size;	// >>> done

	// for the 2D top view
	t_top_view	*top_view;
}	t_game;

// >>> this is the core structure of the game
// >>> it contains the map, the player position, the player direction, etc...
typedef struct s_setup
{
	t_player	*player;
	t_game		*game;
	t_direction	*direction;
	// t_top_view	*top_view;
}	t_setup;

void	*setup_struct_init();
void	init_player_config(t_setup *setup);
void	get_player_position(t_player *player, t_game *game);
int		key_event(int key_code, t_setup *setup);
void	init_game_config(t_game *game);

// drawing 2d top view
void	draw_player_dot(t_player *player, t_game *game);
void	draw_top_view_map(t_game *game, t_player *player);
// void	draw_map(t_game *game);
void	load_images_top_view(t_setup *setup);
void	draw_player_dot(t_player *player, t_game *game);
void	draw_tile(t_game *game, int col, int row, int color);
void	draw_map(t_game *game);

# endif

void	*setup_struct_init()
{
	t_setup	*setup;

	setup = malloc(sizeof(t_setup));
	setup->game = malloc(sizeof(t_game));
	setup->player = malloc(sizeof(t_player));
	setup->game->top_view = malloc(sizeof(t_top_view));
	setup->direction = malloc(sizeof(t_direction));
	if (!setup || !setup->game || !setup->player
		|| !setup->game->top_view || !setup->direction)
	{
		// don't check the leaks i'll git garbage colacter later on here.
		perror("Failed to allocate memory for game");
		exit(1);
	}
	return (setup);
}

char	**map_init() // >>> to remove later on
{
	static char	map[5][11];
	char		**map_ptrs;
	int			i;

	const char *default_map[] = {
		"1111111111",
		"1N00001111",
		"1001000001",
		"1101000111",
		"1111111111",
		NULL
	};

	i = 0;
	while (i < 5)
	{
		strcpy(map[i], default_map[i]);
		i++;
	}

	map_ptrs = malloc(6 * sizeof(char *));
	if (!map_ptrs)
		return (NULL);

	i = 0;
	while (i < 5)
	{
		map_ptrs[i] = map[i];
		i++;
	}
	map_ptrs[i] = NULL;

	return (map_ptrs);
}

void	open_window_2d(t_game *game)
{
	int	width;
	int	height;	

	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		i++;
	}
	// j is column count (width of a row)
	// i is row count (height of map)
	width = j * game->tile_size;
	height = i * game->tile_size;
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	game->screen_width = width;
	game->screen_height = height;
}

void	init_game_config(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (printf("mlx_init filed\n"), exit(EXIT_FAILURE), (void)0);
	game->tile_size = TILE_SIZE;	// TILE_SIZE = 32
	game->map = map_init();	// >>> the map
	// open_window(game);	// >>> 3D view used later on now just 2d to lean how things works
	open_window_2d(game);
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_width, game->screen_height, "Cub2D");
	if (!game->win_ptr)
	{
		perror("Failed to create MLX window");
		exit(EXIT_FAILURE);
	}
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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


// North(up), South(down), East(right), and West(left).

void	init_north_position(t_player *player, int row, int col)
{
	printf("get the North player position\n");

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 0;	// >>> for the row
	player->dir_y = -1;	// >>> for the colum

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = 0.66; // Camera plane X
	// setup->player->plane_y = 0; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

}

void	init_south_position(t_player *player, int row, int col)
{
	printf("get the South player position\n");


	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 0; // South direction
	player->dir_y = 1; // South direction

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = -0.66; // Camera plane X
	// setup->player->plane_y = 0; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

void	init_east_position(t_player *player, int row, int col)
{
	printf("get the East player position\n");


	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 1; // East direction
	player->dir_y = 0; // East direction

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = 0; // Camera plane X
	// setup->player->plane_y = -0.66; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

void	init_west_position(t_player *player, int row, int col)
{
	printf("get the West player position\n");

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = -1; // West direction
	player->dir_y = 0; // West direction

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = 0; // Camera plane X
	// setup->player->plane_y = 0.66; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

}
void	get_player_position(t_player *player, t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
				if (game->map[row][col] == 'N')
					init_north_position(player, row, col);
				else if (game->map[row][col] == 'S')
					init_south_position(player, row, col);
				else if (game->map[row][col] == 'E')
					init_east_position(player, row, col);
				else if (game->map[row][col] == 'W')
					init_west_position(player, row, col);
		}
	}
}


void	init_player_config(t_setup *setup)
{
	t_player *player;

	player = setup->player;
	// seting shit setup here

	// >>> first thing first i have to give it the angle (FOV)
	// >>> before that i have to create an way that convete degree to radians
	player->angle = degrees_to_radians(60);	// >>> FOV of the player
	player->move_speed = 0.05;	// >>> speed of up and down move
	player->rot_speed = 0.05;	// >>> speed of left/right move 
	
	// init the new row/col
	setup->direction->new_row = player->p_y;
	setup->direction->new_col = player->p_x;

	get_player_position(setup->player, setup->game);

}

void	load_images_top_view(t_setup *setup)
{
	t_top_view	*top_view;
	int			width;
	int			height;

	top_view = setup->game->top_view;
    top_view->player_img = mlx_xpm_file_to_image(setup->game->mlx_ptr,
        "top_view/images_src/2d_player.xpm", &width, &height);
    top_view->wall_img = mlx_xpm_file_to_image(setup->game->mlx_ptr,
        "top_view/images_src/square_dark_gray.xpm", &width, &height);
    top_view->free_space_img = mlx_xpm_file_to_image(setup->game->mlx_ptr,
        "top_view/images_src/square_gray.xpm", &width, &height);

    if (!top_view->player_img || !top_view->wall_img || !top_view->free_space_img)
    {
        printf("mlx_xpm_file_to_image failed\n");
        exit(EXIT_FAILURE);
    }
}

void	draw_top_view_map(t_game *game, t_player *player)
{
	int	row;
	int col;

	(void)player;

	row = -1;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
			if (game->map[row][col] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->top_view->wall_img, col * TILE_SIZE, row * TILE_SIZE);
			else 
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->top_view->free_space_img, col * TILE_SIZE, row * TILE_SIZE);
		}
	}
}

void	draw_player_dot(t_player *player, t_game *game)
{
	int	pixel_x;
	int	pixel_y;
	int	radius;
	int	dx;
	int	dy;
	
	// >>> my question is i workd with the (TILE_SIZE = 32) in the 3d view and 2d
	pixel_x = player->p_x * TILE_SIZE; // column → horizontal → x
	pixel_y = player->p_y * TILE_SIZE; // row → vertical → y
	radius = 4;	// radius = 4 -> 8px
	dx = -radius;	// col
	while (dx <= radius)
	{
		// printf("dx = %d\n", dx);
		dy = -radius;	// row
		while (dy <= radius)
		{
			// printf("dy = %d\n", dy);
			if (dx * dx + dy * dy <= radius * radius)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr,
				pixel_x + dx, pixel_y + dy, RED_COLOR);
				dy++;
			}
			dx++;
		}
}

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

int	main()
{
	t_setup *setup;

	// init the setup struct to ready used
	setup = setup_struct_init();
	init_game_config(setup->game);	// init t_game
	init_player_config(setup);	// init t_player
	// first thing here is to load the images
	load_images_top_view(setup);
	draw_top_view_map(setup->game, setup->player);
	draw_player_dot(setup->player, setup->game);
	mlx_key_hook(setup->game->win_ptr, key_event, setup);	
	mlx_loop(setup->game->mlx_ptr);

	return (0);
}
