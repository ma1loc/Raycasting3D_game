/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:32:29 by ytabia            #+#    #+#             */
/*   Updated: 2025/06/30 11:10:47 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"


int	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	unsigned long	result;

	i = 0;
	signe = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		if (signe == (1) && result >= 9223372036854775807)
			return (-1);
		if (signe == (-1) && result >= 9223372036854775807)
			return (0);
	}
	return (result * signe);
}
