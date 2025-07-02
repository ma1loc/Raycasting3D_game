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