# include "cub3d.h"

void	*setup_struct_init()
{
	t_setup	*setup;

	setup = malloc(sizeof(t_setup));
	if (!setup)
	{
		perror("Failed to allocate memory for setup");
		exit(1);
	}
	
	setup->game = malloc(sizeof(t_game));
	if (!setup->game)
	{
		perror("Failed to allocate memory for game");
		exit(1);
	}
	setup->player = malloc(sizeof(t_player));
	if (!setup->player)
	{
		perror("Failed to allocate memory for game");
		exit(1);
	}

	setup->game->top_view = malloc(sizeof(t_top_view));
	if (!setup->game->top_view)
	{
		perror("Failed to allocate memory for game");
		exit(1);
	}
	return (setup);
}
