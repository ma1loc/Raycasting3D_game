# include "cub3D.h"

/*
    // understanding how MLX stores and accesses images? //
        >>> what is the mlx_xpm_file_to_image();
            just a function that takes path of am image
            from the hard drive and store it into the memory
            as an object (if you want to access all the img pixel
            have to call the mlx_get_data_addr)

        >>> what is the mlx_get_data_addr();

    typedef struct s_image
    {
        char	*t_path;
        void	*img_ptr;
        char	*addr;
        int		bpp;
        int		size_line;
        int		endian;
        int		width;
        int		height;
    }	t_image;
	img->addr = mlx_get_data_addr()
	access to the img->addr to get the color of the pixel
*/

/*
    about the wall textures need to know;
    texture mapping to know about it

        understand the intersection direction

        vertical intersection Y-axis
        horizontal intersection X-axis

        if ray hit the horizontal interseciton (record the X)
        if ray hit the vertical intersection (record the Y)

    if hit_horizontal → wall faces N/S → use X for texture
    if hit_vertical   → wall faces E/W → use Y for texture

    alrady have the texture hieght and width 64*64
*/

/*
	>>> core line to understand it <<<

	int color = *(int *)(data_addr + (y * line_length) + (x * (bpp / 8)));
	
	(data_add +)
		>>> data_add hold the first image pixel addr.
			data_add + (y * line_length) moves down to row y.
			data_add + (x * (bpp / 8)) moves right to column x.

	img->addr = mlx_get_data_addr()
		>>> hold addr of the first pixel in full image
	
	(bpp / 8)
		>>> to get bpp from bit to byteh
*/


// function that take the image texture and put it into the wall

void	*get_img_ptr(t_game *game, t_intercept_hit obj_hit)
{
	t_textures *textures;

	textures = &game->textures;
	if (obj_hit.inter_dir == North)
        return (&textures->t_north.img_ptr);
    else if (obj_hit.inter_dir == South)
    	return (&textures->t_south.img_ptr);
    else if (obj_hit.inter_dir == East)
    	return (&textures->t_east.img_ptr);
    return (&textures->t_west.img_ptr);
}

void	set_wall_textures(t_game *game, t_intercept_hit obj_hit, int row, int column)
{
	void		*img_ptr;

	img_ptr = get_img_ptr(game, obj_hit);
	printf("the address is -> %p\n", img_ptr);
}
