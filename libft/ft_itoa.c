/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:25:16 by ytabia            #+#    #+#             */
/*   Updated: 2024/10/30 14:41:39 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(int n)
{
	int				count;
	unsigned int	num;

	num = n;
	count = 0;
	if (n < 0)
	{
		num = -n;
		count++;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static char	*fill_ptr(int num, char *ptr)
{
	if (num == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0';
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	size_t			num_len;
	unsigned int	num;
	char			*ptr;

	num_len = count_numbers(n);
	ptr = malloc(sizeof(char) * (num_len + 1));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		num = -n;
		ptr[0] = '-';
	}
	else
		num = n;
	fill_ptr(num, ptr);
	if (num > 0)
		ptr[num_len] = '\0';
	while (num > 0)
	{
		ptr[--num_len] = (num % 10) + '0';
		num = num / 10;
	}
	return (ptr);
}
