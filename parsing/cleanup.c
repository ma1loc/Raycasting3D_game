#include "../srcs/cub3D.h"

void free_map(t_game *game)
{
    int i;

    if (!game->map)
        return;
    i = 0;
    while (game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    game->map = NULL;
}

void free_config(t_game *game)
{
    int i;
    int num_ids;

    i = 0;
    num_ids = 0;
    while (i < 4)
    {
        if (game->config->ids[i].id[0] != '\0')
            num_ids++;
        i++;
    }
    i = 0;
    while (i < num_ids && game->config->ids[i].path != NULL)
    {
        free(game->config->ids[i].path);
        i++;
    }
    free(game->config);
    game->config = NULL;
}

void free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void free_this_map(char **map, int map_index)
{
    int j;

    j = 0;
    while (j < map_index)
    {
        free(map[j]);
        j++;
    }
    free(map);
}

void cleanup_game(t_game *game)
{
    if (!game)
        return;
    if (game->map)
        free_map(game);
    if (game->config)
        free_config(game);
}
