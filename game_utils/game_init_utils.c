# include "cub3D.h"

void	get_map_size(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
		y++;
	game->cast_data.map_y = y;
	game->cast_data.map_x = ft_strlen(game->map[0]);
}
