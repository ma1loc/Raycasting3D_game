#ifndef CUB3D_H
#define CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <math.h>

typedef struct s_counters
{
    int floor_count;
    int ceiling_count;
}   t_counters;

typedef struct s_ppos
{
    int height;
    int width;
} t_ppos;

typedef struct s_ids
{
    char id[3];
    char *path;
}	t_ids;

typedef struct s_config
{
    t_ids ids[4];
    int floor_rgb[3];
    int ceiling_rgb[3];
}	t_config;

typedef struct s_game
{
    int map_lines;
    int map_start_line;
    int map_height;
    int width;
    char **map;
    t_ppos player_pos;
    t_config *config;
}	t_game;


int	parsing(int argc, char **argv, t_game *game);
int read_map(char *file, t_game *game);
int init_game_config(t_game *game);
int	check_map_extension(char *str);
int check_map_chars(t_game *game);
int	check_map_wall(t_game *game);
int check_config_dup(t_config *config);
int get_map_height(char **map);
int validate_map_char(t_game *game);
int validate_textures(t_config *config);
const char *get_texture_id(const char *line);
int is_texture_line(char *line);
int is_space_valid(char **map, int i, int j, int map_height);
int validate_spaces(t_game *game);
void get_player_position(t_game *game);
int read_config_section(int fd, t_game *game);
int process_line(int fd, t_game *game, t_counters *counters);
int process_config_line(char *line, t_game *game, t_counters *counters);
int process_texture_line(char *line, t_game *game);
int pars_textures(char *line, t_config *config, const char *id);
int pars_rgb(char *line , int *rgb);
int store_and_validat_map(char *file, t_game *game);
int skip_to_map_start(int fd, t_game *game);
int preprocess_map_file(char *file, t_game *game);
char **allocate_map(t_game *game);
int read_map_lines(int fd, char **map, t_game *game);
void free_this_map(char **map, int map_index);
int handle_floor_color(char *line, t_config *config, int *floor_count);
int handle_ceiling_color(char *line, t_config *config, int *ceiling_count);
void *ft_memset(void *str, int c, size_t n);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strncpy(char *dest, const char *src, int n);
int ft_isdigit_str(char *str);
int is_valid_char(char c);
int count_player(char **map);
int count_comma(char *str);
void free_map(t_game *game);
void free_config(t_game *game);
void free_split(char **split);
void cleanup_game(t_game *game);
void err(char *str);
#endif