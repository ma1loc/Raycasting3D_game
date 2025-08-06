/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:00:28 by yanflous          #+#    #+#             */
/*   Updated: 2025/08/06 15:14:46 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
