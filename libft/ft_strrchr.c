/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:33:30 by ytabia            #+#    #+#             */
/*   Updated: 2024/11/09 14:52:03 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
