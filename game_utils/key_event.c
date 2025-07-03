# include "cub3D.h"

// "DONE"
int	key_press(int key_code)
{
	t_game	*game;

	game = g_game();
	if (key_code == ESC_KEY)
		game_exit(EXIT_SUCCESS, NULL);
	
	if (key_code == UP_KEY)
		game->direction.walk_dir = FORWARD;
	if (key_code == DOWN_KEY)
		game->direction.walk_dir = BACKWARD;

	if (key_code == LEFT_KEY)
		game->direction.side_dir = LEFT;
	if (key_code == RIGHT_KEY)
		game->direction.side_dir = RIGHT;

	if (key_code == LEFT_ARROW)
		game->direction.turn_dir = TURN_LEFT;
	if (key_code == RIGHT_ARROW)
		game->direction.turn_dir = TURN_RIGHT;	
	return (0);
}

// --------------- updated -----------------------------
void	upgrade_player_s_dir(t_game *game, double angle)
{
	double	new_angle;

	new_angle = game->player.angle + angle;
	
	// Proper angle normalization
	while (new_angle >= 2 * M_PI)
		new_angle -= 2 * M_PI;
	while (new_angle < 0)
		new_angle += 2 * M_PI;
	
	game->player.angle = new_angle;
}

// "DONE"
void	handle_key_press(t_game *game)
{
    t_direction	*dir;

    dir = &game->direction;
	if (dir->walk_dir == FORWARD)
		upgrade_player_dir(game, FORWARD, false);
	if (dir->walk_dir == BACKWARD)
		upgrade_player_dir(game, BACKWARD, false);

	if (dir->side_dir == LEFT)
		upgrade_player_dir(game, LEFT, true);
	if (dir->side_dir == RIGHT)
		upgrade_player_dir(game, RIGHT, true);

	if (dir->turn_dir == TURN_LEFT)
		upgrade_player_s_dir(game, -ROT_SPEED);
	if (dir->turn_dir == TURN_RIGHT)
		upgrade_player_s_dir(game, ROT_SPEED);
}

// "DONE"
int	key_release(int key_code)
{
	t_direction	*dir;

	dir = &g_game()->direction;
	if (key_code == UP_KEY || key_code == DOWN_KEY)
		dir->walk_dir = 0;
	else if (key_code == LEFT_KEY || key_code == RIGHT_KEY)
		dir->side_dir = 0;
	else if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		dir->turn_dir = 0;
	return (0);
}
// ------------------------------------------------------------


void	draw_square(int x, int y, int size, int color)
{
	t_game	*game;
	int		i;
	int		j;

	game = g_game();
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_2d_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (g_game()->map[y])
	{
		x = 0;
		while (g_game()->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_square(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, D_GRAY_COLOR);
			else if (game->map[y][x] == '0')
				draw_square(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, GRAY_COLOR);
			x++;
		}
		y++;
	}
}


void	draw_player(t_game *game)
{
	int	player_screen_x, player_screen_y;
	int	player_size;

	player_size = TILE_SIZE / 2;
	
	player_screen_x = (int)game->player.pos.p_x - (player_size / 2);
	player_screen_y = (int)game->player.pos.p_y - (player_size / 2);
	
	draw_square(player_screen_x, player_screen_y, player_size, RED_COLOR);
}


void	main_img_randring(t_game *game)
{
	draw_2d_map(game);
	draw_player(game);
	
	mlx_put_image_to_window(game->window.mlx_ptr, 
		game->window.win_ptr, 
		game->window.main_img.img_ptr, 0, 0);
}


int	game_loop()
{
	t_game *game;

	game = g_game();

	handle_key_press(game);
	main_img_randring(game);
	
	return (0);
}
