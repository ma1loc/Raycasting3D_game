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

// # define TILE_SIZE 128
# define TILE_SIZE 64

# define FOV 60.0

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.1

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define UP_KEY    XK_w
# define DOWN_KEY  XK_s
# define LEFT_KEY  XK_a
# define RIGHT_KEY XK_d
# define LEFT_ARROW XK_Left
# define RIGHT_ARROW XK_Right  
// key left and right arrow

# define ESC_KEY   XK_Escape



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

typedef struct s_direction {
	int	walk_dir;
	int	side_dir;
	int turn_dir;
}	t_direction;

typedef struct s_top_view
{
	void	*player_img;
	void	*wall_img;
	void	*free_space_img;
}	t_top_view;

typedef	struct s_player
{
	double	rot_angle;
	double	move_speed;
	double	rot_speed;

	double	p_x;
	double	p_y;

	double	dir_x;
	double	dir_y;

	double	plane_x;
	double	plane_y;

}	t_player;

typedef struct s_ray_data
{
	double	wall_dist;
	double	hit_x;
	double	hit_y;
	// Wall orientation (vertical/horizontal)
} t_ray_data;

// >>> array of the ray data
typedef struct s_ray_casting
{
	int			ray_nbr;
	double		fov_angle;
	double		ray_angle;
	double		angle_step;
	t_ray_data	*rays;
}	t_ray_casting;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	// int		map_width;
	// int		map_height;
	// for the 3D view
	int		screen_width;
	int		screen_height;
	// int		tile_size;
	char	**map;

	// for the 2D top view
	t_top_view	*top_view;
}	t_game;

typedef struct s_setup
{

	t_player		*player;
	t_game			*game;
	t_direction		*direction;
	t_ray_casting	*ray_casting;
}	t_setup;

void	*setup_struct_init();
void	init_player_config(t_setup *setup);
void	get_player_position(t_player *player, t_game *game);
int		key_event(int key_code, t_setup *setup);
void	init_game_config(t_game *game);
double	degrees_to_radians(int degree);

int	key_release(int key_code, t_setup *setup);

// drawing 2d top view
void	draw_player_dot(t_player *player, t_game *game);
void	draw_top_view_map(t_game *game, t_player *player);
// void	draw_map(t_game *game);
void	load_images_top_view(t_setup *setup);
void	draw_player_dot(t_player *player, t_game *game);
void	draw_tile(t_game *game, int col, int row, int color);
void	draw_map(t_game *game);
int		double_to_int(double nbr);
int		game_loop(t_setup *setup);
int		is_wall_at(t_setup *setup, double x, double y);
int		is_valid_move(t_setup *setup, double new_x, double new_y);
void    init_ray_config(t_setup *setup);
void    cast_rays(t_setup *setup);

# endif


void	*setup_struct_init()
{
	t_setup	*setup;

	setup = malloc(sizeof(t_setup));
	setup->game = malloc(sizeof(t_game));
	setup->player = malloc(sizeof(t_player));
	setup->game->top_view = malloc(sizeof(t_top_view));
	setup->direction = malloc(sizeof(t_direction));
	setup->ray_casting = malloc(sizeof(t_ray_casting));
	if (!setup || !setup->game || !setup->player
		|| !setup->game->top_view || !setup->direction
		|| !setup->ray_casting)
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

void	open_window(t_game *game)
{
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

void	init_game_config(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (printf("mlx_init filed\n"), exit(EXIT_FAILURE), (void)0);

	// >>>>>>> not the main map just a test <<<<<<<<<
	game->map = map_init();
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	open_window(game);

}

void	init_north_position(t_player *player, int row, int col)
{
	printf("get the North player position\n");
	player->rot_angle = degrees_to_radians(270);

	player->p_y = row + 0.5; 
	player->p_x = col + 0.5;

	player->dir_x = 0;
	player->dir_y = -1;
}

void	init_south_position(t_player *player, int row, int col)
{
	printf("get the South player position\n");
	player->rot_angle = degrees_to_radians(90);

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 0;
	player->dir_y = 1;
}

void	init_east_position(t_player *player, int row, int col)
{
	printf("get the East player position\n");
	player->rot_angle = degrees_to_radians(0);

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 1;
	player->dir_y = 0;
}

void	init_west_position(t_player *player, int row, int col)
{
	printf("get the West player position\n");
	player->rot_angle = degrees_to_radians(180);

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = -1;
	player->dir_y = 0;
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

double	degrees_to_radians(int degree)
{
	double	radian;

	radian = degree * M_PI / 180.0;
	return (radian);
}

void	init_player_config(t_setup *setup)
{
	t_player	*player;
	t_direction	*dir;

	player = setup->player;
	dir = setup->direction;
	player->move_speed = MOVE_SPEED;
	player->rot_speed = ROT_SPEED;
	dir->turn_dir = 0;
	dir->walk_dir = 0;
	dir->side_dir = 0;
	get_player_position(setup->player, setup->game);
}

void    init_ray_config(t_setup *setup)
{
    t_ray_casting   *ray_casting;
    t_player        *player;
    
    ray_casting = setup->ray_casting;
    player = setup->player;
    
    ray_casting->ray_nbr = SCREEN_WIDTH;
    // ray_casting->ray_nbr = SCREEN_WIDTH / 2; // drop the qulity and get batter performnace
    ray_casting->fov_angle = degrees_to_radians(FOV);
    // get the left-most ray
    ray_casting->ray_angle = player->rot_angle - (ray_casting->fov_angle / 2);
    // distance between rays
    ray_casting->angle_step = ray_casting->fov_angle / ray_casting->ray_nbr;

    ray_casting->rays = malloc(sizeof(t_ray_data) * ray_casting->ray_nbr);
    if (!ray_casting->rays)
        return (printf("rays mallocation filed\n"), exit(EXIT_FAILURE));
    memset(ray_casting->rays, 0, sizeof(t_ray_data) * ray_casting->ray_nbr);
}

// >>> before start casting ask what you need before casting rays?
    // - how we cast that ray?
    
    // - how to move to next ray?, this is how, right?; yes
        // >>> ray_casting->ray_angle += ray_casting->angle_step;


void    cast_rays(t_setup *setup)
{
    int     colmun;

    (void)setup;
    colmun = 0;
    while (colmun < SCREEN_WIDTH)
    {
        // >>> start casting start here
        // i will set it later on
    }
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
	double	pixel_x;
	double	pixel_y;
	int		radius;
	int		dx;
	int		dy;

	pixel_x = player->p_x * TILE_SIZE;
	pixel_y = player->p_y * TILE_SIZE;
	
	radius = 4;
	dx = -radius;	// >>> col
	while (dx <= radius)
	{
		dy = -radius;	// >>> row
		while (dy <= radius)
		{
			if (dx * dx + dy * dy <= radius * radius)
				mlx_pixel_put(game->mlx_ptr, game->win_ptr,
					(int)(pixel_x + dx + 0.5), (int)(pixel_y + dy + 0.5), RED_COLOR);
			dy++;
		}
		dx++;
	}
}

int	is_wall_at(t_setup *setup, double x, double y)
{
	int map_x = (int)(x);
	int map_y = (int)(y);

	if (x < 0 || y < 0)
		return (1);
	if (!setup->game->map[map_y] || !setup->game->map[map_y][map_x])
		return (1);
	if (setup->game->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	is_valid_move(t_setup *setup, double new_x, double new_y)
{
	double	radius = 0.03;


	if (is_wall_at(setup, new_x + radius, new_y))
		return (0);
	if (is_wall_at(setup, new_x - radius, new_y))
		return (0);
	if (is_wall_at(setup, new_x, new_y + radius))
		return (0);
	if (is_wall_at(setup, new_x, new_y - radius))
		return (0);
	return (1);
}

void	wall_collision(t_setup *setup, double x, double y, int *moved)
{
	t_player *player;

	player = setup->player;
	if (is_valid_move(setup, x, player->p_y))
    {
        player->p_x = x;
        *moved = 1;
    }
    else if (is_valid_move(setup, player->p_x, y))
    {
        player->p_y = y;
        *moved = 1;
    }
}

void	re_drow(t_setup *setup, int *moved)
{
   	if (*moved)
    {
        mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
        draw_top_view_map(setup->game, setup->player);
        draw_player_dot(setup->player, setup->game);
    }
}

void	update_walk_dir(t_setup *setup, int *moved)
{
	t_player *player;
	double move_step;
	double	new_p_x;
	double	new_p_y;

	player = setup->player;
	// cos(a) => gives the adjacent side move
	// sin(a) => gives the oppesite side move

	move_step = setup->direction->walk_dir * player->move_speed;
    new_p_x = player->p_x + cos(player->rot_angle) * move_step;
    new_p_y = player->p_y + sin(player->rot_angle) * move_step;
	printf("walk cos -> %f\n", new_p_x);
	printf("walk sin -> %f\n", new_p_y);
    if (is_valid_move(setup, new_p_x, new_p_y))
    {
        player->p_x = new_p_x;
        player->p_y = new_p_y;
        *moved = 1;
    }
	// else	// wall collision put it later on
	// 	wall_collision(setup, new_p_x, new_p_y, moved);
}

void	update_side_dir(t_setup *setup, int *moved)
{
	t_player *player;
	double move_step;
	double	new_p_x;
	double	new_p_y;

	player = setup->player;

	move_step = setup->direction->side_dir * player->move_speed;
    new_p_x = player->p_x + cos(player->rot_angle + (M_PI / 2)) * move_step;
    new_p_y = player->p_y + sin(player->rot_angle + (M_PI / 2)) * move_step;
    printf("side cos -> %f\n", new_p_x);
	printf("side sin -> %f\n", new_p_y);
	if (is_valid_move(setup, new_p_x, new_p_y))
    {
        player->p_x = new_p_x;
        player->p_y = new_p_y;
        *moved = 1;
    }
}

int game_loop(t_setup *setup)
{
	int			moved;
    t_direction	*dir;
    t_player	*player;

	moved = 0;
	dir = setup->direction;
	player = setup->player;

    if (dir->walk_dir != 0)
		update_walk_dir(setup, &moved);
	if (dir->side_dir != 0)
		update_side_dir(setup, &moved);
    if (dir->turn_dir != 0)
    {
        player->rot_angle += dir->turn_dir * player->rot_speed;
        moved = 1;
    }
	re_drow(setup, &moved);
    return (0);
}

int	key_event(int key_code, t_setup *setup)
{
	t_direction	*dir;

	dir = setup->direction;
	if (key_code == ESC_KEY)
		exit(EXIT_SUCCESS);
	else if (key_code == UP_KEY)
		dir->walk_dir = 1;
	else if (key_code == DOWN_KEY)
		dir->walk_dir = -1;
	else if (key_code == LEFT_KEY)
		dir->side_dir = -1;
	else if (key_code == RIGHT_KEY)
		dir->side_dir = 1;
	else if (key_code == LEFT_ARROW)
		dir->turn_dir = -1;
	else if (key_code == RIGHT_ARROW)
		dir->turn_dir = 1;
	
	if (dir->walk_dir != 0 || dir->turn_dir != 0 || dir->side_dir != 0)
		game_loop(setup);
	return (0);
}

int	key_release(int key_code, t_setup *setup)
{
	t_direction	*dir;

	dir = setup->direction;
	if (key_code == UP_KEY || key_code == DOWN_KEY)
		dir->walk_dir = 0;
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
		dir->side_dir = 0;
	else if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		dir->turn_dir = 0;
	return (0);
}

int	main()
{
	t_setup *setup;
	
	setup = setup_struct_init();
	init_game_config(setup->game);
	init_player_config(setup);
	init_ray_config(setup);
	load_images_top_view(setup);

	draw_top_view_map(setup->game, setup->player);
	draw_player_dot(setup->player, setup->game);
	
	printf("rot -> %f\n", setup->player->rot_angle);
	printf("cos -> %f\n", cos(setup->player->rot_angle));

	// cast_rays(setup);

	mlx_hook(setup->game->win_ptr, KeyPress, 1L << 0, key_event, setup);
	mlx_hook(setup->game->win_ptr, KeyRelease, 1L << 1, key_release, setup);
	
	mlx_loop(setup->game->mlx_ptr);

	return (0);
}
