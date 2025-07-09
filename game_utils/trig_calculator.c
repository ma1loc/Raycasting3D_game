# include "cub3D.h"

// "DONE"
double	degrees_to_radians(int degree)
{
	return (degree * M_PI / 180);
}

double	get_distance(t_coord p_pos, t_coord hit)
{
	double	dx;
	double	dy;

	// no matter of the p_pos.x or the hit.x orderd
	dx = p_pos.x - hit.x;
	dy = p_pos.y - hit.y;
	return (sqrt((dx * dx) + (dy * dy)));
}
