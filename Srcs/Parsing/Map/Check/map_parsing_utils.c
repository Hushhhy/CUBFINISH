/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:16:22 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/11 14:02:30 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	_there_is_walls(char **map, int y, int x)
{
	if (!_check_rows(map, y, x))
		return (false);
	if (!_check_cols(map, y, x))
		return (false);
	return (true);
}

bool	_check_spaces(char **map, int y, int x)
{
	if (!_check_space_row(map, y, x))
		return (false);
	if (!_check_space_col(map, y, x))
		return (false);
	return (true);
}

bool	_check_rows(char **map, int y, int x)
{
	int	i;

	i = x;
	if (map[y][0] == '0')
		return (false);
	while (i >= 0)
	{
		if (!_check_left(map, y, i))
			return (false);
		if (map[y][i] == '1')
			break ;
		i--;
	}
	i = x;
	while (map[y][i])
	{
		if (!_check_right(map, y, i))
			return (false);
		if (map[y][i] == '1')
			break ;
		i++;
	}
	return (true);
}

bool	_check_cols(char **map, int y, int x)
{
	int	i;

	i = y;
	while (i >= 0)
	{
		if (!_check_up(map, i, x))
			return (false);
		if (map[i][x] == '1')
			break ;
		i--;
	}
	i = y;
	while (map[i])
	{
		if (!_check_down(map, i, x))
			return (false);
		if (map[i][x] == '1')
			break ;
		i++;
	}
	return (true);
}
