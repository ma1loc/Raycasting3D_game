# include "cub3d.h"

void	load_images_top_view(t_setup *setup)
{
	// void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

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
