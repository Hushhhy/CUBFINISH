/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_path_format.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:30:51 by pgrellie          #+#    #+#             */
/*   Updated: 2025/02/05 19:02:40 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

static void	check_xpm_extension(char *name, int start, t_game *game)
{
	int	len;

	len = start;
	while (name[len] && (name[len] != ' ' && name[len]
			!= '\t' && name[len] != '\n'))
		len++;
	if (len <= 4 || name[len - 1] != 'm' || name[len - 2] != 'p'
		|| name[len - 3] != 'x' || name[len - 4] != '.')
		exit(_error_msg_free("Texture", ERR_XPM, 1, game));
}

void	_check_texname(char *name, t_game *game)
{
	int	i;

	i = skip_whitespace(name);
	if (!ft_strncmp(name, "NO ", 3) || !ft_strncmp(name, "SO ", 3)
		|| !ft_strncmp(name, "EA ", 3) || !ft_strncmp(name, "WE ", 3))
	{
		i += 3;
		i += skip_whitespace(name + i);
		check_xpm_extension(name, i, game);
	}
}
