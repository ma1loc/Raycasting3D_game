# include "cub3d.h"

int	is_wall(t_setup *setup, int key_code)
{
	t_direction	*dir = setup->direction;
	t_player	*player = setup->player;

	if (setup->game->map[(int)dir->new_p_y][(int)dir->new_p_x] == '1')
	{
		dir->new_p_x = player->p_x;
		dir->new_p_y = player->p_y;
		return (1);
	}

	if (key_code == UP_KEY || key_code == DOWN_KEY)
		player->p_y = dir->new_p_y;
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
		player->p_x = dir->new_p_x;

	return (0);
}

int	key_event(int key_code, t_setup *setup)
{
	t_direction	*dir = setup->direction;
	t_player	*player = setup->player;

	dir->new_p_x = player->p_x;
	dir->new_p_y = player->p_y;

	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(0), 0);

	if (key_code == UP_KEY)
		dir->new_p_y -= 0.1;
	else if (key_code == DOWN_KEY)
		dir->new_p_y += 0.1;
	else if (key_code == LEFT_KEY)
		dir->new_p_x -= 0.1;
	else if (key_code == RIGHT_KEY)
		dir->new_p_x += 0.1;

	if (is_wall(setup, key_code))
		return (0);

	mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
	draw_top_view_map(setup->game, setup->player);
	draw_player_dot(setup->player, setup->game);

	return (0);
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

double radius = 4.0 / TILE_SIZE;
double x = direction->new_p_x;
double y = direction->new_p_y;

if (
    setup->game->map[(int)(y - radius)][(int)(x - radius)] == '1' ||
    setup->game->map[(int)(y - radius)][(int)(x + radius)] == '1' ||
    setup->game->map[(int)(y + radius)][(int)(x - radius)] == '1' ||
    setup->game->map[(int)(y + radius)][(int)(x + radius)] == '1'
)
{
    direction->new_p_x = player->p_x;
    direction->new_p_y = player->p_y;
    return (1);
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int	is_wall(t_setup *setup, int key_code)
{
	t_direction	*direction;
	t_player	*player;
	double		radius;
	double 		x;
	double		y;
	
	radius = 4 / TILE_SIZE;
	player = setup->player;
	direction = setup->direction;
	x = direction->new_p_x;
	y = direction->new_p_y;

	if (setup->game->map[(int)(y - radius)][(int)(x - radius)] == '1' ||
		setup->game->map[(int)(y - radius)][(int)(x + radius)] == '1' ||
		setup->game->map[(int)(y + radius)][(int)(x - radius)] == '1' ||
		setup->game->map[(int)(y + radius)][(int)(x + radius)] == '1')
	{
		direction->new_p_x = player->p_x;
		direction->new_p_y = player->p_y;
		return (1);
	}
	else if (key_code == UP_KEY || key_code == DOWN_KEY)
		setup->player->p_y = direction->new_p_y;
	
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
		setup->player->p_x = direction->new_p_x;

	return (0);
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

if (key_code == UP_KEY)	// -1
		player->p_x = cos(player->rot_angle) * dir->walk_dir * player->move_speed;
		player->p_y = sin(player->rot_angle) * dir->walk_dir * player->move_speed;
	else if (key_code == DOWN_KEY)	// +1
		player->p_x = cos(player->rot_angle) * dir->walk_dir * player->move_speed;
		player->p_y = sin(player->rot_angle) * dir->walk_dir * player->move_speed;
// or like this
if (key_code == UP_KEY || key_code == DOWN_KEY)
	player->p_x = cos(player->rot_angle) * dir->walk_dir * player->move_speed;
	player->p_y = sin(player->rot_angle) * dir->walk_dir * player->move_speed;

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// Fixed rotation angle initialization
void	init_north_position(t_player *player, int row, int col)
{
	printf("get the North player position\n");
	player->rot_angle = degrees_to_radians(270); // North = 270° (3π/2)

	player->p_y = row + 0.5; 
	player->p_x = col + 0.5;

	player->dir_x = 0;	// North direction
	player->dir_y = -1;	// North direction (negative Y)
}

void	init_south_position(t_player *player, int row, int col)
{
	printf("get the South player position\n");
	player->rot_angle = degrees_to_radians(90); // South = 90° (π/2)

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 0;  // South direction
	player->dir_y = 1;  // South direction (positive Y)
}

void	init_east_position(t_player *player, int row, int col)
{
	printf("get the East player position\n");
	player->rot_angle = degrees_to_radians(0); // East = 0° (0)

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 1;  // East direction (positive X)
	player->dir_y = 0;  // East direction
}

void	init_west_position(t_player *player, int row, int col)
{
	printf("get the West player position\n");
	player->rot_angle = degrees_to_radians(180); // West = 180° (π)

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = -1; // West direction (negative X)
	player->dir_y = 0;  // West direction
}

// Fixed movement logic
void	update_pposition(t_setup *setup, int key_code)
{
	t_player	*player;
	t_direction	*dir;
	double		move_step;
	double		new_x, new_y;

	player = setup->player;
	dir = setup->direction;
	
	// Handle forward/backward movement
	if (key_code == UP_KEY || key_code == DOWN_KEY)
	{
		move_step = dir->walk_dir * player->move_speed;
		
		// Calculate new position based on current rotation angle
		new_x = player->p_x + cos(player->rot_angle) * move_step;
		new_y = player->p_y + sin(player->rot_angle) * move_step;
		
		// Basic boundary check (you should add proper wall collision)
		if (new_x >= 0 && new_y >= 0 && 
			new_x < setup->game->map_width && new_y < setup->game->map_height)
		{
			player->p_x = new_x;
			player->p_y = new_y;
		}
		
		printf("move_step: %f, new_x: %f, new_y: %f\n", move_step, player->p_x, player->p_y);
	}
	// Handle rotation
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
	{
		player->rot_angle += dir->turn_dir * player->rot_speed;
		
		// Keep angle in range [0, 2π]
		if (player->rot_angle < 0)
			player->rot_angle += 2 * M_PI;
		else if (player->rot_angle >= 2 * M_PI)
			player->rot_angle -= 2 * M_PI;
		
		// Update direction vectors based on new angle
		player->dir_x = cos(player->rot_angle);
		player->dir_y = sin(player->rot_angle);
		
		printf("rotation angle: %f degrees\n", player->rot_angle * 180.0 / M_PI);
	}
}

// Fixed key event handling
int	key_event(int key_code, t_setup *setup)
{
	t_direction	*dir;

	dir = setup->direction;
	if (key_code == ESC_KEY)
		return (printf("exit_the_game (ESC) pressed\n"), exit(0), 0);

	// Set movement direction (FIXED)
	if (key_code == UP_KEY)
		dir->walk_dir = 1;      // Forward is positive
	else if (key_code == DOWN_KEY)
		dir->walk_dir = -1;     // Backward is negative
	else if (key_code == LEFT_KEY)
		dir->turn_dir = -1;     // Turn left (counter-clockwise)
	else if (key_code == RIGHT_KEY)
		dir->turn_dir = 1;      // Turn right (clockwise)
	else
		return (0);	

	// Update position and redraw
	update_pposition(setup, key_code);
	printf("Player position: x=%.2f, y=%.2f, angle=%.1f°\n", 
		   setup->player->p_x, setup->player->p_y, 
		   setup->player->rot_angle * 180.0 / M_PI);
	
	mlx_clear_window(setup->game->mlx_ptr, setup->game->win_ptr);
	draw_top_view_map(setup->game, setup->player);
	
	return (0);
}

// Add this function to initialize map dimensions
void	calculate_map_dimensions(t_game *game)
{
	int i, j, max_width = 0;
	
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j > max_width)
			max_width = j;
		i++;
	}
	game->map_height = i;
	game->map_width = max_width;
}

// Call this in init_game_config after setting up the map
void	init_game_config(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (printf("mlx_init filed\n"), exit(EXIT_FAILURE), (void)0);
	game->tile_size = TILE_SIZE;

	game->map = map_init();
	calculate_map_dimensions(game); // Add this line
	
	open_window_2d(game);
	
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_width, game->screen_height, "Cub2D");
	if (!game->win_ptr)
	{
		perror("Failed to create MLX window");
		exit(EXIT_FAILURE);
	}
}