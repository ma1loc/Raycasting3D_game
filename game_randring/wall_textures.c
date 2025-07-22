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

// void    get_idea(t_game *game)
// {
//     game->textures.t_north.height;
// }