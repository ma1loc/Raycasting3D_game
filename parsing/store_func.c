#include "cub3D.h"


int store_and_validat_map(char *file, t_game *game)
{
    char **map;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (-1);
    if (skip_to_map_start(fd, game) == -1)
        return (close(fd), -1);
    preprocess_map_file(file, game);
    map = allocate_map(game);
    if (!map)
        return (close(fd), 1);
    if (read_map_lines(fd, map, game) == -1)
        return (close(fd), 1);
    game->map = map;
    close(fd);
    return (0);
}

int skip_to_map_start(int fd, t_game *game)
{
    char *line;
    int i;

    i = 0;
    while (i < game->map_start_line)
    {
        line = get_next_line(fd);
        if (!line)
            return (-1);
        free(line);
        i++;
    }
    return (0);
}

int preprocess_map_file(char *file, t_game *game)
{
    char *line;
    int fd;
    int i;
    int map_lines;

    i = 0;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (-1);
    while (i < game->map_start_line)
    {
        line = get_next_line(fd);
        free(line);
        i++;
    }
    map_lines = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        map_lines++;
        free(line);
    }
    game->map_lines = map_lines;
    close(fd);
    return (0);
}

char **allocate_map(t_game *game)
{
    char **map;
    int j;

    map = malloc(sizeof(char *) * (game->map_lines + 1));
    if (!map)
        return (NULL);
    j = 0;
    while (j <= game->map_lines)
    {
        map[j] = NULL;
        j++;
    }
    return (map);
}
int ft_isspace(char c)
{
    if(c == ' ' || c == '\t' ||
        c == '\n' || c == '\v' ||
        c == '\f' || c == '\r')
        return(1);
    return(0);
}

int check_white_spaces(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!ft_isspace(str[i]))
            return (1);
        i++;
    }
    return (0);
}

int read_map_lines(int fd, char **map, t_game *game)
{
    char *line;
    int map_index;

    map_index = 0;
    while (map_index < game->map_lines)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (line[0] == '\n')
        {
            free(line);
            if (map_index < game->map_lines)
            {
                free_this_map(map, map_index);
                return (-1);
            }
            continue;
        }
        if (!check_white_spaces(line))
        {
            free(line);
            continue;
        }
        map[map_index] = line;
        map_index++;
    }
    map[map_index] = NULL;
    return (0);
}