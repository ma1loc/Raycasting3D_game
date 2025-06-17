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

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

// the key presed to add
# define UP_KEY    XK_w
# define DOWN_KEY  XK_s
# define LEFT_KEY  XK_a
# define RIGHT_KEY XK_d
# define ESC_KEY   XK_Escape

# define TILE_SIZE      32
# define PLAYER_SPEED   0.1
# define ROTATE_SPEED   0.05


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

typedef	struct s_player
{
	// >>> player position in the map(x, y)
	double	p_x;
	double	p_y;
	// >>> player direction in the map (north, south, east, west)
	double	dir_x;
	double	dir_y;
	/// >>> player camera plane for the (fov)field of view of the player
	// double	plane_x;
	// double	plane_y;
}	t_player;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		map_width;
	int		map_height;
	int		screen_width;
	int		screen_height;
}	t_game;

// >>> this is the core structure of the game
// >>> it contains the map, the player position, the player direction, etc...
typedef struct s_setup
{
	t_player	*player;
	t_game		*game;
}	t_setup;
