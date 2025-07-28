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

// ---------------------------------------------------------------------------

// this map have a glitch player jsut see the four direction with no free space, inter hit blue wall to go outside
//         11111111111
//         10000000001
// 1111111110000000001  
// 1000000000000000001111111111
// 1000000000000000000000000001
// 1000000000000000000000000001    1111
// 1000000000111111110000000001    1001
// 10000000001      10000000001    1111
// 10000001111      10000000001
// 1000000000111111110000000001
// 1000000000000000000000000001
// 1000000000000000000000000001
// 1111111100000000000011100001111111111
//        111000000000010000W00010000001
//        100000000000000000000010000001
// 1111111100000111111001110000000000001
// 10000000000001 1000001 10000010000001
// 11111111111111 1111111 11111111111111

// -------------------------------------------------------------------------

// this map have a problem, thinks so in the parsing with player rotaion angle
//         1111111111111111111111111
//         1000000000110000000000001
//         1011000001110000000000001
//         1001000000000000000000001
// 111111111011000001110000000000001
// 100000000011000001110111111111111
// 11110111111111011100000010001
// 11110111111111011101010010001
// 11000000110101011100000010001
// 10000000000000001100000010001
// 10000000000000001101010010001
// 11000001110101011111011110N0111
// 11110111 1110101 101111010001
// 11111111 1111111 111111111111

// -------------------------------------------------------------------------

// to-do; fix the mpa chape (even with tab at first map)
// - heap-buffer-overflow
// >>>>>>>>>>>>>>>> input <<<<<<<<<<<<<<<
// '                     '	tabsss
// 11111111111
// 10000000001
// 10100000W01
// 11111111111
// >>>>>>>>>>>>>>>> output <<<<<<<<<<<<<<<
/*
'	                           '
        11111111111
        10000000001
        10100000W01
        11111111111
*/

// -------------------------------------------------------------------------

// - the view is fucked up
// >>>>>>>>>>>>>>>> input <<<<<<<<<<<<<<<
// new line
// '        ' tab
        // 11111111111
        // 10000000001
        // 10100000W01
        // 11111111111

// >>>>>>>>>>>>>>>> output <<<<<<<<<<<<<<<
/*
'        '<- tab
        11111111111
        10000000001
        10100000W01
        11111111111
*/

/*
    i have a problem to fix with the function is_hit i get the map_y and map_x at the first initalization
    that i think the lines of the map is rectangle but is not that mean's i have to get
    a diffrent logic hit intersection becousse the map it can be like this:
        11
        11111111111
        10000000001
        10100000W01
        11111111111
        11
    and what i i've done is this 
    void	get_map_size(t_game *game)
    {
        int	y;

        y = 0;
        while (game->map[y])
            y++;
        game->cast_data.map_y = y;
        game->cast_data.map_x = ft_strlen(game->map[0]);
    }
    i don't even know that the map most be  sometimes not rectangle
    and i based on the first line and check the hit like this
    
    int     is_hit(t_game *game, t_coord intercept)
    {
        int map_x;
        int map_y;

        map_x = (int)(intercept.x / TILE_SIZE);
        map_y = (int)(intercept.y / TILE_SIZE);
        printf("---------------------------------------------------------------------\n");
        printf("map_x -> %d | game->cast_data.map_x -> %d\n", map_x, game->cast_data.map_x);
        printf("map_y -> %d | game->cast_data.map_y -> %d\n", map_y, game->cast_data.map_y);
        printf("---------------------------------------------------------------------\n");

        if (map_x < 0 || map_x >= game->cast_data.map_x ||
            map_y < 0 || map_y >= game->cast_data.map_y)
            return (1);

        if (map_x > (int)(ft_strlen(game->map[map_y])))
            return (1);
        
        return (game->map[map_y][map_x] == '1');

    }

    that make the intersection is not correct at all
    */

// ---------------- learning push ------------------------

// 1# about the projection plane calculation
/*
    having the angle of the ray and
    the opposite side
    using the tan() function
    to get the distance from the playe to the projectin plane
*/