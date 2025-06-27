# ifndef CUB3D_H
# define CUB3D_H

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

// # define GRAY_COLOR 0xAAAAAA
// # define D_GRAY_COLOR 0x222222
#define RED_COLOR 0xFF0000

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

// # define TILE_SIZE 128
# define TILE_SIZE 64

# define FOV 60.0

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.1

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define UP_KEY    XK_w
# define DOWN_KEY  XK_s
# define LEFT_KEY  XK_a
# define RIGHT_KEY XK_d
# define LEFT_ARROW XK_Left
# define RIGHT_ARROW XK_Right  
// key left and right arrow

# define ESC_KEY   XK_Escape



// typedef struct s_image
// {
//     void    *img_ptr;
//     char    *data;
//     int     bpp;
//     int     size_line;
//     int     endian;
//     int     width;
//     int     height;
// }   t_image;

typedef struct s_direction {
	int	walk_dir;
	int	side_dir;
	int turn_dir;
}	t_direction;

typedef struct s_top_view
{
	void	*player_img;
	void	*wall_img;
	void	*free_space_img;
}	t_top_view;

typedef	struct s_player
{
	double	rot_angle;
	double	move_speed;
	double	rot_speed;

	double	p_x;
	double	p_y;

	double	dir_x;
	double	dir_y;

	double	plane_x;
	double	plane_y;

}	t_player;

typedef struct s_ray_data
{
	double	wall_dist;
	double	hit_x;
	double	hit_y;
	// Wall orientation (vertical/horizontal)
} t_ray_data;

// >>> array of the ray data
typedef struct s_ray_casting
{
	int			ray_nbr;
	double		fov_angle;
	double		ray_angle;
	double		angle_step;
	t_ray_data	*rays;
}	t_ray_casting;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	// int		map_width;
	// int		map_height;
	// for the 3D view
	int		screen_width;
	int		screen_height;
	// int		tile_size;
	char	**map;

	// for the 2D top view
	t_top_view	*top_view;
}	t_game;

typedef struct s_setup
{

	t_player		*player;
	t_game			*game;
	t_direction		*direction;
	t_ray_casting	*ray_casting;
}	t_setup;

void	*setup_struct_init();
void	init_player_config(t_setup *setup);
void	get_player_position(t_player *player, t_game *game);
int		key_event(int key_code, t_setup *setup);
void	init_game_config(t_game *game);
double	degrees_to_radians(int degree);

int	key_release(int key_code, t_setup *setup);

// drawing 2d top view
void	draw_player_dot(t_player *player, t_game *game);
void	draw_top_view_map(t_game *game, t_player *player);
// void	draw_map(t_game *game);
void	load_images_top_view(t_setup *setup);
void	draw_player_dot(t_player *player, t_game *game);
void	draw_tile(t_game *game, int col, int row, int color);
void	draw_map(t_game *game);
int		double_to_int(double nbr);
int		game_loop(t_setup *setup);
int		is_wall_at(t_setup *setup, double x, double y);
int		is_valid_move(t_setup *setup, double new_x, double new_y);
void    init_ray_config(t_setup *setup);
void    cast_rays(t_setup *setup);


# endif
