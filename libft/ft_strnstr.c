/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:55:24 by ytabia            #+#    #+#             */
/*   Updated: 2024/11/09 15:24:24 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	if (str2[0] == '\0')
		return ((char *)str1);
	if (n == 0)
		return (NULL);
	i = 0;
	while (str1[i] && i < n)
	{
		j = 0;
		while (str1[i + j] == str2[j] && (i + j < n))
		{
			if (str1[i + j] == str2[j] && str2[j + 1] == '\0')
				return ((char *)str1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
