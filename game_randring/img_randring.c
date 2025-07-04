# include "cub3D.h"

// "DONE"
void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;
    t_image	*img;

	if (x < 0 || y < 0)
		return ;
    img = &game->window.main_img;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

// >>> Draw 2d map
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

void	draw_line(t_game *game, int x, int y, int line_size)
{
	int		i;
	int		j;

	(void)y;
	(void)x;
	i = 0;
	while (i < line_size)
	{
		j = 0;
		while (j < line_size)
		{
			my_mlx_pixel_put(game, x, y + j, GREEN_CLOOR);
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
			else if (game->map[y][x] == '0'
				|| game->map[y][x] == *g_game()->player_pos.player)
				draw_square(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, GRAY_COLOR);
			x++;
		}
		y++;
	}	
}

void	draw_player(t_game *game)
{
	int	player_screen_x;
	int player_screen_y;
	int	player_size;
	int	line_size;

	line_size = 60;
	player_size = TILE_SIZE / 3;
	player_screen_x = (int)game->player.pos.p_x - (player_size / 2);
	player_screen_y = (int)game->player.pos.p_y - (player_size / 2);
	
	draw_square(player_screen_x, player_screen_y, player_size, RED_COLOR);
	draw_line(game, player_screen_x, player_screen_y, line_size);
}
