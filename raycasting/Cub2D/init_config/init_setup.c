# include "cub3d.h"

void	*setup_struct_init()
{
	t_setup	*setup;

	setup = malloc(sizeof(t_setup));
	setup->game = malloc(sizeof(t_game));
	setup->player = malloc(sizeof(t_player));
	setup->game->top_view = malloc(sizeof(t_top_view));
	setup->direction = malloc(sizeof(t_direction));
	if (!setup || !setup->game || !setup->player
		|| !setup->game->top_view || !setup->direction)
	{
		// don't check the leaks i'll git garbage colacter later on here.
		perror("Failed to allocate memory for game");
		exit(1);
	}
	return (setup);
}
