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

	// get the projection plane distance by getting the adjacent side?
	// adjacent						= 		opposite 	 /	 tan(angle)
	// proj_plane_dist = (SCREEN_WIDTH / 2) / tan(game->player.fov / 2);