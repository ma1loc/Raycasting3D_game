/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:36:16 by ytabia            #+#    #+#             */
/*   Updated: 2025/06/30 11:13:38 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"


char	*ft_strchr(const char *str, int search_str)
{
	char	ch;
	int		i;

	ch = (char)search_str;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)str + i);
	return (NULL);
}
