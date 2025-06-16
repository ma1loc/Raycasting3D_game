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

typedef	struct s_player
{
	// >>> player position in the map(x, y)
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
