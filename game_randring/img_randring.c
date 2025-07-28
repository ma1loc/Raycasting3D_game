/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_randring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:32:12 by yanflous          #+#    #+#             */
/*   Updated: 2025/07/28 13:33:37 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;
	t_image	*img;

	if (x < 0 || y < 0)
		return ;
	img = &game->window.main_img;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
