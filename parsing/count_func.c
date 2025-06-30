#include "cub3D.h"

int count_player(char **map)
{
    int i;
    int j;
    int count_player;

    i = 0;
    count_player = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                count_player++;
            j++;
        }
        i++;
    }
    return (count_player);
}

int count_comma(char *str)
{
    int i;
    int comma;

    comma = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == ',')
            comma++;
        i++;
    }
    return (comma);
}

int get_map_height(char **map)
{
    int height;

    height = 0;
    while (map[height])
        height++;
    return (height);
}

void get_player_position(t_game *game)
{
	int i;
	int j;
	int row_len;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		row_len = ft_strlen(game->map[i]);
		while (j < row_len)
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->player_pos.height = i;
				game->player_pos.width = j;
				return;
			}
			j++;
		}
		i++;
	}
}

void err(char *str)
{
    while (*str)
        write(2, str++, 1);
}