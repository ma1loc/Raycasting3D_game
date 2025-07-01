/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:12:50 by ytabia            #+#    #+#             */
/*   Updated: 2024/11/09 12:44:43 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	char			*s;
	unsigned char	ch;

	s = (char *)str;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		s[i] = ch;
		i++;
	}
	return (str);
}
