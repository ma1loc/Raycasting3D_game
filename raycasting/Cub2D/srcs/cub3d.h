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

// >>> pixel based to use
// # define TILE_SIZE 32
# define TILE_SIZE 64
// # define TILE_SIZE 128

// >>> filed of view
# define FOV 60.0

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05

// >>> this is just for the 3d view
# define SCREEN_WIDTH 1920
// >>> this is just for the 3d view
# define SCREEN_HEIGHT 1080

// >>> to remove it latter and based on the map char now just a test
# define ANGEL 'N'

// the key presed to add
# define UP_KEY    XK_w
# define DOWN_KEY  XK_s
# define LEFT_KEY  XK_a
# define RIGHT_KEY XK_d
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
	double	walk_dir;  // -1 = backward, +1 = forward
	double	turn_dir;  // -1 = left,     +1 = right
}	t_direction;


typedef struct s_top_view
{
	void	*player_img;
	void	*wall_img;
	void	*free_space_img;
}	t_top_view;

typedef	struct s_player
{
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	double	rot_angle;	// >>> player angle facing -> [S, N, E, W]
	double	move_speed; // >>> player speed in the map movements, player->move_speed = 0.05
	double	rot_speed;	// >>> rotat left and right
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	// >>> player position in the map(x, y)
	// how to init this at first just loop thghout the map and git it value of int not float
	double	p_x;
	double	p_y;

	// >>> player direction in the map (north, south, east, west)
	double	dir_x;
	double	dir_y;

	/// >>> player camera plane for the (fov)field of view of the player
	double	plane_x;
	double	plane_y;

}	t_player;

typedef struct s_game
{
	void	*mlx_ptr;	// >>> done
	void	*win_ptr;	// >>> done
	int		map_width;	// >>> done
	int		map_height;	// >>> done
	// for the 3D view
	int		screen_width;	// this is just for the 3d view
	int		screen_height;	// // this is just for the 3d view
	int		tile_size;	// >>> done
	char	**map;		// >>> done

	// for the 2D top view
	t_top_view	*top_view;
}	t_game;

// >>> this is the core structure of the game
// >>> it contains the map, the player position, the player direction, etc...
typedef struct s_setup
{
	t_player	*player;
	t_game		*game;
	t_direction	*direction;
}	t_setup;

void	*setup_struct_init();
void	init_player_config(t_setup *setup);
void	get_player_position(t_player *player, t_game *game);
int		key_event(int key_code, t_setup *setup);
void	init_game_config(t_game *game);
double	degrees_to_radians(int degree);

// drawing 2d top view
void	draw_player_dot(t_player *player, t_game *game);
void	draw_top_view_map(t_game *game, t_player *player);
// void	draw_map(t_game *game);
void	load_images_top_view(t_setup *setup);
void	draw_player_dot(t_player *player, t_game *game);
void	draw_tile(t_game *game, int col, int row, int color);
void	draw_map(t_game *game);
int		double_to_int(double nbr);


# endif
