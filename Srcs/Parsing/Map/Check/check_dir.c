/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:17:26 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/13 13:07:19 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	_check_top_bot(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i])
	{
		if (line[i] == '\n')
			return (true);
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	_check_right(char **map, int y, int i)
{
	if (map[y][i] != '1' && map[y][i] != 'N' && map[y][i] != 'S'
		&& map[y][i] != 'E' && map[y][i] != 'W' && map[y][i] != '0'
		&& map[y][i] != ' ')
		return (false);
	if (map[y][i] == ' ')
		if (!_check_spaces(map, y, i))
			return (false);
	return (true);
}

bool	_check_left(char **map, int y, int i)
{
	if (map[y][i] != '1' && map[y][i] != 'N' && map[y][i] != 'S'
		&& map[y][i] != 'E' && map[y][i] != 'W' && map[y][i] != '0'
		&& map[y][i] != ' ')
		return (false);
	if (map[y][i] == ' ')
		if (!_check_spaces(map, y, i))
			return (false);
	return (true);
}

bool	_check_up(char **map, int i, int x)
{
	if (map[i][x] != '1' && map[i][x] != 'N' && map[i][x] != 'S'
		&& map[i][x] != 'E' && map[i][x] != 'W' && map[i][x] != '0'
		&& map[i][x] != ' ')
		return (false);
	if (map[i][x] == ' ')
		if (!_check_spaces(map, i, x))
			return (false);
	return (true);
}

bool	_check_down(char **map, int i, int x)
{
	if (map[i][x] != '1' && map[i][x] != 'N' && map[i][x] != 'S'
		&& map[i][x] != 'E' && map[i][x] != 'W' && map[i][x] != '0'
		&& map[i][x] != ' ')
		return (false);
	if (map[i][x] == ' ')
		if (!_check_spaces(map, i, x))
			return (false);
	return (true);
}
