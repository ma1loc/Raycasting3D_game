/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:40:29 by ytabia            #+#    #+#             */
/*   Updated: 2024/11/09 16:10:09 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	len_size;
	void	*ptr;

	if (size != 0 && nitems > __SIZE_MAX__ / size)
		return (NULL);
	len_size = nitems * size;
	ptr = malloc(len_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, len_size);
	return (ptr);
}
