// simple 2D map first
// second 3D projection
// North(up), South(down), East(right), and West(left).
// flickering to fix
// pressed keyyyyyyyyyyyyyyyy
// to create my_mlx_put_pixel() later on
// >>>>>>>>>>>>>>>>>>> TO kNOW && TO-DO <<<<<<<<<<<<<<<<<<<<<<
	// to know what is the steps under the hood calling mlx_init()?
	// i think about the mlx as engen taht i have to start it (mlx_init) to get start woking with it
	// to knwo why the mlx_put_pixel flickering and slow?
	// to know how mlx_do_key_autorepeaton(void *mlx_ptr) work?
	// to know what the fucking diff mlx_hook, mlx_loop_hook, mlx_loop
	// is have to convert the ROT_SPEED to radinas?
	// read about the cos and sin.
	// what is the fish-eye in the cub3d consipte?
// >>>>>>>>>>>>>>>>>>>>> TO-DO >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// TO-DO: create-function converting form binnary to hex for the colors
	// TO-DO: create-function coverd the mlx_piexl_put


// >>> FOV(60) in the radinas / SCREEN_WIDTH to get the distance between rays 
// >>> rotation_angle is the angle that the player facing
// >>> why i have to subtrating the half of the FOV then i cast the rays?
// >>> create an image buffer / mlx_pixel_put
// >>> have to set the ray thi
// >>> loog thghout the colmuns to cast the rays

// fix the key w, a, s, d, moves 
// number of rays >>> "DONE"
// get the filed of view >>> "DONE"
// subtract the 30 degrees from, ray_angle(player rotation angle - (FOV_ANGLE / 2)) >>> "DONE"
// converting the FOV to randins in fov_angle. >>> "DONE"
// distance btween every ray -> ray_angle += (FOV/NUM_OF_RAYS)? "DONE"
// have to know the wall_distance to drow the wall

// trace the ray until it hit the wall
// how to get the lengh of the ray the cast and hit the wall?
// is the num of rays get from window_width / wall_strip_width ?
// what's mean cast ray ber frame?
// is i have to create an arry of rays?
// So each ray will need its own small struct to store this data.

// >>> before start casting ask what you need before casting rays?
    // - how we cast that ray?
    
    // - how to move to next ray?, this is how, right?; yes
        // >>> ray_casting->ray_angle += ray_casting->angle_step;

// ---------------------------------------------------------------------

// 				to-do
// >>> draw the player casing line.

// >>> start the ray-casting.
	// You start from: player_angle - (FOV / 2)
	// End at: player_angle + (FOV / 2)
	// Ray angle
	// Hit point (x, y)
	// Tile hit (map coordinates)
	
	// Was it vertical or horizontal?	"DONE"
	// Distance to hit					"DONE"
	// Texture offset (for drawing)

	// How DDA/grid stepping works?
	// How to detect vertical vs horizontal hits?
		// 	if (hit_vertical)
		//     apply_vertical_texture_logic();
		// else
		//     apply_horizontal_texture_logic();

	// How to apply textures cleanly?

// >>> fix the up and down key behaver.

// |||||||||||||||||||| ray-casting |||||||||||||||||||||||||
// what you need to start the ray-casting?
	// >>> ray_nbr -> how much rays to cast
	// >>> angle_step -> distance between each ray
    // >>> befor casting any ray we have (player direction)
        // and we need to get the left most ray to cast the first ray to right most
        // ray_angle = player->rot_angle - (rc->fov_angle / 2);
        // ray_angle =         45        -       60       / 2
        // ray_angle = 15 (left-most)
    // >>> horizontal check <<<
        //  x_intersection | y_intersection
        //  A_y = P_y / TILE_SIZE * TILE_SIZE;
        //  A_x = P_x + P_y - A_y / tan(ray_angle)
        //  ---------------------------------------
        //  x_step = TILE_SIZE / tan(ray_angle)
        //  y_step = TILE_SIZE;
    // >>> vertical check <<<
        //  x_intersection | y_intersection
        //  x_step = TILE_SIZE
        //  y_step = TILE_SIZE * tan(ray_angle)

// ---------------------------------------------------------------------------

double	get_distance(t_coord p_pos, t_coord hit)
{
	double	dx;
	double	dy;

	// no matter of the p_pos.x or the hit.x orderd
	dx = p_pos.x - hit.x;
	dy = p_pos.y - hit.y;
	return (sqrt((dx * dx) + (dy * dy)));
}


void    get_closest_distance(
    t_game *game, t_coord horizontal, t_coord vertical)
{
    t_coord p_pos;
    double  horizontal_dist;
    double  vertical_dist;

    p_pos = game->player.p_pos;

    horizontal_dist = get_distance(p_pos, horizontal);
    vertical_dist = get_distance(p_pos, vertical);
    if (horizontal_dist < vertical_dist)
        game->cast_data.horizontal_hit = true;
    else
        game->cast_data.horizontal_hit = false;
}


int     is_hit(t_game *game, t_coord intercept)
{
    int map_x = (int)(intercept.x / TILE_SIZE);
    int map_y = (int)(intercept.y / TILE_SIZE);

    if (map_x < 0 || map_x >= game->width ||
        map_y < 0 || map_y >= game->map_height)
        return (1);
    return (game->map[map_y][map_x] == '1');
}

t_intercept_hit	check_intersection_hit(
    t_game *game, t_intercept_hit *intercept, t_coord step)
{
    while (true)
    {
        if (is_hit(game, intercept->intercept))
            break;
        intercept->intercept.x += step.x;
        intercept->intercept.y += step.y;
    }
    return (*intercept);
}

// ----------- horizontal intersection -----------
t_intercept_hit	get_horizontal_intersection(
    t_game *game, t_coord p_pos, double ray_angle)
{
    double          slope;
    t_intercept_hit intercept;
    t_coord         step;

    slope = tan(ray_angle);
    if (ray_angle > 0 && ray_angle < M_PI)
    {
        intercept.intercept.y = floor(
            p_pos.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
        intercept.inter_dir = South;
        step.y = TILE_SIZE;
    }
    else
    {
		intercept.intercept.y = floor(
            p_pos.y / TILE_SIZE) * TILE_SIZE - 0.0001;
        intercept.inter_dir = North;
        step.y = -TILE_SIZE;
    }
    intercept.intercept.x = p_pos.x + (
        intercept.intercept.y - p_pos.y) / slope;
    step.x = step.y / slope;
	return (check_intersection_hit(game, &intercept, step));
}

// ----------- vertical intersection -----------
t_intercept_hit get_vertical_intersection(
    t_game *game, t_coord p_pos, double ray_angle)
{
    double          slope;
    t_intercept_hit intercept;
    t_coord         step;

    slope = tan(ray_angle);
    if (ray_angle < M_PI / 2 || ray_angle > (M_PI * 3) / 2)
    {
        intercept.intercept.x = floor(
            p_pos.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
        intercept.inter_dir = East;
        step.x = TILE_SIZE;
    }
    else
    {
        intercept.intercept.x = floor(
            p_pos.x / TILE_SIZE) * TILE_SIZE - 0.0001;
        intercept.inter_dir = West;
        step.x = -TILE_SIZE;
    }
    intercept.intercept.y = p_pos.y + (
        intercept.intercept.x - p_pos.x) * slope;
    step.y = step.x * slope;
    return (check_intersection_hit(game, &intercept, step));
}

t_intercept_hit cast_ray(t_game *game, double ray_angle)
{
    t_intercept_hit	horizontal_hit;
	t_intercept_hit vertical_hit;

    horizontal_hit = get_horizontal_intersection(
        game, game->player.p_pos, ray_angle);
    vertical_hit = get_vertical_intersection(
        game, game->player.p_pos, ray_angle);
    get_closest_distance(
        game, horizontal_hit.intercept, vertical_hit.intercept);
    if (game->cast_data.horizontal_hit)
        return (horizontal_hit);
    return (vertical_hit);
}

// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
void	x_draw_line(t_game *game, double x0, double y0, double x1, double y1, int color)
{
	double	dx = x1 - x0;
	double	dy = y1 - y0;
	int		steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	double	x_inc = dx / steps;
	double	y_inc = dy / steps;
	double	x = x0;
	double	y = y0;
	int		i = 0;

	while (i <= steps)
	{
		my_mlx_pixel_put(game, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
		i++;
	}
}
// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------

void	draw_front_view(t_game *game)
{
	int				column;
	double			ray_angle;
	t_coord			p_pos;
	t_intercept_hit	ray_hit;

	column = 0;
	p_pos = game->player.p_pos;
	ray_angle = game->player.angle - (game->player.fov / 2);
	while (column < game->cast_data.ray_nbr)
	{
		ray_hit = cast_ray(game, ray_angle);

		// >>> this like just an test of the ray is cast correctly before the 3d set
		x_draw_line(game, p_pos.x, p_pos.y, ray_hit.intercept.x, ray_hit.intercept.y, GREEN_CLOOR);

		ray_angle += game->cast_data.angle_step;
		column++;
	}
}

// >>> main game randring engine start here
int	game_loop(t_game *game)
{
	handle_key_press(game);		// key-hadling

	// 2D-top-view
	draw_2d_map(game);
	draw_player(game);

	draw_front_view(game);		// >>> currently working here <<<
	
	mlx_put_image_to_window(game->window.mlx_ptr, 
		game->window.win_ptr, 
		game->window.main_img.img_ptr, 0, 0);

	return (0);
}