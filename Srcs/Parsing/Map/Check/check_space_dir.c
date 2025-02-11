/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:18:21 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/13 14:01:20 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	_check_space_row(char **map, int y, int x)
{
	int	i;

	i = x;
	while (i >= 0)
	{
		if (map[y][i] == '1')
			break ;
		if (!_check_space_left(map, y, i))
			return (false);
		i--;
	}
	i = x;
	while (map[y][i])
	{
		if (map[y][i] != '1' && map[y][i] != 'N' && map[y][i] != 'S'
			&& map[y][i] != 'E' && map[y][i] != 'W' && map[y][i] != '0'
			&& map[y][i] != ' ')
			return (false);
		if (map[y][i] == '1')
			break ;
		i++;
	}
	return (true);
}

bool	_check_space_left(char **map, int y, int i)
{
	if (map[y][i] != '1' && map[y][i] != 'N' && map[y][i] != 'S'
		&& map[y][i] != 'E' && map[y][i] != 'W' && map[y][i] != '0'
		&& map[y][i] != ' ')
		return (false);
	if (i == 0)
		return (false);
	return (true);
}

bool	_check_space_col(char **map, int y, int x)
{
	int	i;

	i = y;
	while (i >= 0)
	{
		if (map[i][x] == '1')
			break ;
		if (!_check_space_up(map, i, x))
			return (false);
		i--;
	}
	i = y;
	while (map[i])
	{
		if (map[i][x] != '1' && map[i][x] != 'N' && map[i][x] != 'S'
			&& map[i][x] != 'E' && map[i][x] != 'W' && map[i][x] != '0'
			&& map[i][x] != ' ')
			return (false);
		if (map[i][x] == '1')
			break ;
		if (!map[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	_check_space_up(char **map, int i, int x)
{
	if (map[i][x] != '1' && map[i][x] != 'N' && map[i][x] != 'S'
		&& map[i][x] != 'E' && map[i][x] != 'W' && map[i][x] != '0'
		&& map[i][x] != ' ')
		return (false);
	if (i == 0)
		return (false);
	return (true);
}
