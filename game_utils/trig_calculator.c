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

	dx = hit.x - p_pos.x;
	dy = hit.y - p_pos.y;
	return (sqrt((dx * dx) + (dy * dy)));
}
