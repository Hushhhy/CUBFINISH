/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:04:47 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/13 13:06:28 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_floor_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "F ", 2))
	{
		i += 2;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!game->data.floor_color)
		{
			_get_floor(line, game);
			game->data.floor_color = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.floor_color[j++] = line[i++];
			game->data.floor_color[j] = '\0';
		}
		else
			exit(_error_msg_free("Error", ERR_FLOOR, 1, game));
	}
}

void	_ceiling_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "C ", 2))
	{
		i += 2;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!game->data.ceiling_color)
		{
			_get_ceiling(line, game);
			game->data.ceiling_color = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.ceiling_color[j++] = line[i++];
			game->data.ceiling_color[j] = '\0';
		}
		else
			exit(_error_msg_free("Error", ERR_CEILING, 1, game));
	}
}
