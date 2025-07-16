# include "cub3D.h"

// >>> draw 2d map
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

	i = 0;
    dx = cos(game->player.angle);
    dy = sin(game->player.angle);
    px = game->player.p_pos.x;
    py = game->player.p_pos.y;
    while (i < line_size)
    {
        draw_x = (int)(px + dx * i);
        draw_y = (int)(py + dy * i);
        my_mlx_pixel_put(game, draw_x, draw_y, GREEN_COLOR);
		i++;
	}
}

void draw_player(t_game *game)
{
    int player_size;
    int player_screen_x;
    int player_screen_y;
    int line_size;

	player_size = TILE_SIZE / 3;
	player_screen_x = (int)(game->player.p_pos.x - player_size / 2);
	player_screen_y = (int)(game->player.p_pos.y - player_size / 2);
	line_size = 60;

	draw_line(game, line_size);
    // draw_square(player_screen_x, player_screen_y, player_size, RED_COLOR);
    draw_square(player_screen_x, player_screen_y, player_size, game->window.floor_color);
}

double distance_between_points(double x, double y, double x1, double y1) {
    double dx = x1 - x;
    double dy = y1 - y;
    return sqrt(dx * dx + dy * dy);
}

void x_draw_line(double ray_angle, t_game *game, double x0, double y0, double x1, double y1, int color)
{
    double dis = distance_between_points(x0, y0, x1, y1);

    double step_x = cos(ray_angle);
    double step_y = sin(ray_angle);
    double x = x0;
    double y = y0;
    for (double r = 0; r <= dis; r += 1.0) {
        my_mlx_pixel_put(game, (int)x, (int)y, color);
        x += step_x;
        y += step_y;
    }
}

// void x_draw_line(double ray_angle, t_game *game, double x0, double y0, double x1, double y1, int color)
// {
// 	(void)x0;
// 	(void)y0;
// 	(void)ray_angle;
// 	my_mlx_pixel_put(game, (int)x1, (int)y1, color);
// }

void	draw_rays_view(t_game *game)
{
	int				column;
	t_coord			p_pos;
	double			ray_angle;
	t_intercept_hit	ray_hit;

	column = 0;
	p_pos = game->player.p_pos;
	ray_angle = game->player.angle - (game->player.fov / 2);
	
	while (column < game->cast_data.ray_nbr)
	{
		ray_angle = normalize_angle(ray_angle);
		ray_hit = cast_ray(game, ray_angle);

		if (ray_hit.inter_dir == North)
			x_draw_line(ray_angle,game, p_pos.x, p_pos.y, ray_hit.intercept.x, ray_hit.intercept.y, BLUE_COLOR);
		if (ray_hit.inter_dir == South)
			x_draw_line(ray_angle,game, p_pos.x, p_pos.y, ray_hit.intercept.x, ray_hit.intercept.y, YELLOW_COLOR);
		if (ray_hit.inter_dir == East)
			x_draw_line(ray_angle,game, p_pos.x, p_pos.y, ray_hit.intercept.x, ray_hit.intercept.y, WHITE_COLOR);
		if (ray_hit.inter_dir == West)
			x_draw_line(ray_angle,game, p_pos.x, p_pos.y, ray_hit.intercept.x, ray_hit.intercept.y, GREEN_COLOR);

		ray_angle += game->cast_data.angle_step;
		column++;
	}
}
