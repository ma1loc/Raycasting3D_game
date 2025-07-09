# include "cub3D.h"

// "DONE"
double	degrees_to_radians(int degree)
{
	return (degree * M_PI / 180);
}

// >>> a2 + b2 = c2
// ((H.x - P.x) * (H.x - P.x) + (H.y - P.y) * (H.y - P.y));
double	get_distance(t_coord p_pos, t_coord hit)
{
	double	dx;
	double	dy;

	dx = p_pos.x - hit.x;
	dy = p_pos.y - hit.y;
	return (sqrt((dx * dx) + (dy * dy)));
}
