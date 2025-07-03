#include "cub3D.h"


int read_map(char *file, t_game *game)
{
    int fd;

    game->map_start_line = 0;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        err("Error:\ncannot open map file\n"), exit(1);
    if (init_game_config(game))
        exit(1);
    if (read_config_section(fd, game)) ///
        return (1);
    if (validate_textures(game->config))
        cleanup_game(game), exit(1);
    if (store_and_validat_map(file, game))
        err("Error:\ninvalid map\n"), exit(1);
    return (0);
}
int handle_floor_color(char *line, t_config *config, int *floor_count)
{
    (*floor_count)++;
    if (*floor_count > 1)
        err("Error:\nduplicate identifier\n"), exit(1);
    if (pars_rgb(line + 2, config->floor_rgb))
        err("Error\ninvalid floor color format\n"), exit(1);
    return (0);
}

int handle_ceiling_color(char *line, t_config *config, int *ceiling_count)
{
    (*ceiling_count)++;
    if (*ceiling_count > 1)
        err("Error:\nduplicate identifier\n"), exit(1);
    if (pars_rgb(line + 2, config->ceiling_rgb))
        err("Error:\ninvalid ceiling color format\n"), exit(1);
    return (0);
}

int init_game_config(t_game *game)
{
    game->config = malloc(sizeof(t_config));
    if (!game->config)
        return (1);
    ft_memset(game->config, 0, sizeof(t_config));
    return (0);
}

int read_config_section(int fd, t_game *game)
{
    t_counters counters;
    int result;

    counters.floor_count = 0;
    counters.ceiling_count = 0;
    while (1)
    {
        result = process_line(fd, game, &counters);
        if (result == -1)
            break;
        if (result == 1)
            return (close(fd), 1);
        if (result == 2)
            break;
    }
    if (result == -1) // EOF
        return (1);
    return (0);
}
