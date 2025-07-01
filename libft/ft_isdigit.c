/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:28:06 by ytabia            #+#    #+#             */
/*   Updated: 2025/05/26 18:38:38 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

