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
// // -------------------------------------------------------------

// void	draw_square(int x, int y, int size, int color)
// {
// 	t_game	*game;
// 	int		i;
// 	int		j;

// 	game = g_game();
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			my_mlx_pixel_put(game, x + i, y + j, color);
// 			j++;	
// 		}
// 		i++;
// 	}
// }

// void	main_img_randring(t_game *game)
// {
// 	int px = game->player.pos.p_x;
// 	int py = game->player.pos.p_y;

// 	draw_square(px, py, 20, RED_COLOR);

// 	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
// 		game->window.main_img.img_ptr, 0, 0);
// }
