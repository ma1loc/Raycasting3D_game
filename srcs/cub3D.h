#ifndef CUB3D_H
#define CUB3D_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# define BLUE_COLOR 0x0000FF
# define WAITE_COLOR 0xFFFFFF
# define YELLOW_COLOR 0xFFFF00
# define GRAY_COLOR 0xAAAAAA
# define D_GRAY_COLOR 0x222222
# define RED_COLOR 0xFF0000
# define GREEN_CLOOR 0x00FF00

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define TILE_SIZE 64
// # define TILE_SIZE 128

# define FOV 60

# define MOVE_SPEED 1.5
# define ROT_SPEED 0.05

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define UP_KEY    XK_w
# define DOWN_KEY  XK_s
# define LEFT_KEY  XK_a
# define RIGHT_KEY XK_d
# define LEFT_ARROW XK_Left
# define RIGHT_ARROW XK_Right  
# define ESC_KEY   XK_Escape

# define FORWARD 1
# define BACKWARD -1
# define LEFT -1
# define RIGHT 1
# define TURN_LEFT -1
# define TURN_RIGHT 1

// # include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_counters
{
    int floor_count;
    int ceiling_count;
}   t_counters;

typedef struct s_ppos
{
    int height;
    int width;
    char player[2];
} t_ppos;

typedef struct s_ids
{
    char    id[3];
    char    *path;
}   t_ids;

typedef struct s_config
{
    t_ids ids[4];
    int floor_rgb[3];
    int ceiling_rgb[3];
} t_config;

// ----------------------------------------

// bpp; how many bits are used to represent one pixel (32bit)
// size_line; size_line = how many bytes in one row
// endian; 2

typedef struct s_image
{
	char	*t_path;
	void	*img_ptr;
	char	*addr;		// "DONE"
	int		bpp;		// "DONE" to see
	int		size_line;	// "DONE" to see
	int		endian;		// ""
	int		width;
	int		height;
}	t_image;

// 00000000 00000000 00000000 00000000
//     T       R        G         B
// x >> 24  & (0xff) = T
// x >> 16 = R
// x >> 8  = G
// x       = B
// ff ff ff ff
// ----------------------------------------

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	main_img;	// >>>  main image frame
}	t_window;

// ----------------------------------------

typedef struct s_direction
{
	int		walk_dir;
	int		side_dir;
	int		turn_dir;
}	t_direction;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef	struct s_player
{
	double 			fov;
	double			angle;
	t_coord			p_pos;
}	t_player;

typedef struct s_cast_data
{
	int		ray_nbr;
	double	angle_step;
	double	wall_dist;
	bool	horizontal_hit;
	int		map_x;
	int		map_y;
}			t_cast_data;

typedef struct	s_textures
{
	t_image		t_north;
	t_image		t_south;
	t_image		t_east;
	t_image		t_west;
}				t_textures;

typedef enum	s_dir
{
	North = 1,
	South,
	East,
	West
}	t_dir;

typedef	struct	s_intercept_hit
{
	t_coord	intercept;
	t_dir	inter_dir;
}	t_intercept_hit;

typedef struct s_game
{
    int				map_lines;
    int				map_start_line;
    int				map_height;
    int				width;
    char			**map;
    t_ppos			player_pos;
    t_config		*config;

	// ----------------- ray-casting part
	t_window		window;
	t_player		player;
	t_direction		direction;
	t_cast_data		cast_data;
	t_textures		textures;

}	t_game;

// ----------------------------------------

int		ft_isalpha(int c);
int     ft_isdigit(char *str);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy( char *dest, const char *src, size_t size );
size_t	ft_strlcat( char *dest, const char *src, size_t size );
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int search_str);
char	*ft_strrchr(const char *str, int search_str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *str1, const char *str2, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// ----------------------------------------

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
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

// 
// -------------------------------- parsing part --------------------------------
// ------------- init game (movements, textures, other stuff... ) -----------------
t_game	*g_game(void);
int		game_loop(t_game *game);
void	init_mlx_window(void);
void	init_textures(void);
void	set_game_textures(void);
void	init_player_dir(void);
int		key_press(int key_code);
int		key_release(int key_code);
void	handle_key_press(t_game *game);
double	degrees_to_radians(int degree);
void	game_exit(int exit_nbr, char *msg);
void	draw_square(int x, int y, int size, int color);
void	upgrade_player_s_dir(t_game *game, double angle);
void	upgrade_player_dir(t_game *game, int dir, bool strafe);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		is_wall(t_game *game, double x, double y);
double	get_distance(t_coord p_pos, t_coord hit);
void    get_closest_distance(
    t_game *game, t_coord horizontal, t_coord vertical);
	
	
	
// ------------------------- top-view --------------------
void	draw_2d_map(t_game *game);
void	draw_player(t_game *game);
	
// -------------------------------------------------------------------------
// ------------- ray-casting -----------------
// void	casting_rays(t_game *game);
// void	cast_rays(t_game *game, double ray_angle);
t_intercept_hit cast_ray(t_game *game, double ray_angle);

#endif
