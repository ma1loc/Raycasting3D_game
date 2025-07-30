/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:00:28 by ytabia            #+#    #+#             */
/*   Updated: 2025/07/30 18:01:06 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_dub_texture_id(t_config *config, int index)
{
	if (config->ids[index].id[0] != '\0')
	{
		err("Error:\nduplicate texture identifier\n");
		exit(1);
	}
}

void	check_texture_extension(char *extension)
{
	if (!extension || ft_strcmp(extension, ".xpm") != 0)
	{
		err("Error:\ntexture must be .xpm file\n");
		exit(1);
	}
}

void	check_texture_path(int fd)
{
	if (fd < 0)
	{
		err("Error:\ninvalid textures path\n");
		exit(1);
	}
}
