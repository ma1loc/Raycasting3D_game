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

void	draw_line(t_game *game, int line_size)
{
    int     i;
    double  dx;
    double  dy;
    double  px;
    double  py;
    int     draw_x;
    int     draw_y;

    dx = cos(game->player.angle);
    dy = sin(game->player.angle);
    px = game->player.pos.p_x;
    py = game->player.pos.p_y;
    for (i = 0; i < line_size; i++)
    {
        draw_x = (int)(px + dx * i);
        draw_y = (int)(py + dy * i);
        my_mlx_pixel_put(game, draw_x, draw_y, GREEN_CLOOR);
    }
}

void draw_player(t_game *game)
{
    int player_size = TILE_SIZE / 3;
    int player_screen_x = (int)(game->player.pos.p_x - player_size / 2);
    int player_screen_y = (int)(game->player.pos.p_y - player_size / 2);
    int line_size = 60;

	draw_line(game, line_size);
    draw_square(player_screen_x, player_screen_y, player_size, RED_COLOR);
}