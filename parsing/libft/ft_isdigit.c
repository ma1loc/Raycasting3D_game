/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:28:06 by ytabia            #+#    #+#             */
/*   Updated: 2025/06/30 11:14:34 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"


int ft_isdigit_str(char *str)
{
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;

    if (str[i] == '\0') // empty after skipping spaces
        return 1;       // no digits found
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 1;   
        i++;
    }
    return 0;
}

