# include "cub3D.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;
    t_image img;

    img = game->window.main_img;
	dst = img.addr + (y * img.size_line + x * (img.bpp / 8));
	*(unsigned int*)dst = color;
}
