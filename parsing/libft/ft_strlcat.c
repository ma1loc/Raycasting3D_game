/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:54:31 by ytabia            #+#    #+#             */
/*   Updated: 2025/06/30 11:15:19 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"


size_t	ft_strlcat( char *dest, const char *src, size_t size )
{
	size_t				i;
	size_t				j;
	size_t				dest_len;
	size_t				src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (size + src_len);
	j = dest_len;
	i = 0;
	while (src[i] && dest_len + i < size - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}
