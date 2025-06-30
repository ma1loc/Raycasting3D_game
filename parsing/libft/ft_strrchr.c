/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:33:30 by ytabia            #+#    #+#             */
/*   Updated: 2025/06/30 11:15:35 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

char	*ft_strrchr(const char *str, int search_str)
{
	char	ch;
	size_t	len;

	len = ft_strlen(str);
	ch = (char)search_str;
	if (ch == '\0')
		return ((char *)str + len);
	while (len > 0)
	{
		len--;
		if (str[len] == ch)
			return ((char *)str + len);
	}
	return (NULL);
}
