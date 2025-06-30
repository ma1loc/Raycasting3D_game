# include "cub3D.h"


void	*setup_struct_init(t_game *game)
{
	t_setup	*setup;

	setup = malloc(sizeof(t_setup));
	setup->game = game;
	setup->player = malloc(sizeof(t_player));
	setup->top_view = malloc(sizeof(t_top_view));
	setup->direction = malloc(sizeof(t_direction));
	setup->ray_casting = malloc(sizeof(t_ray_casting));
	if (!setup || !setup->player || !setup->top_view
		|| !setup->direction || !setup->ray_casting)
	{
		// don't check the leaks i'll git garbage colacter later on here.
		perror("Failed to allocate memory for game");
		exit(1);
	}
	return (setup);
}
