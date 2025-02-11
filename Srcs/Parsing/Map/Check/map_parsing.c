/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:04:42 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/30 15:26:08 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_check_the_map(t_game *game)
{
	if (!game->data.map)
		exit(_error_msg_free("MAP", ERR_NO_MAP, 1, game));
	if (_get_map_height(game->data.map) < 3)
		exit(_error_msg_free("MAP", ERR_SMALL_MAP, 1, game));
	if (!_check_nb_player(game->data.map, game))
		exit(_error_msg_free("MAP", ERR_PLAYER, 1, game));
	if (!_check_closed_map(game))
		exit(_error_msg_free("MAP", ERR_CLOSED, 1, game));
	_map_realloc(game);
	game->data.map_int = _convert_map(game);
}

bool	_check_nb_player(char **map, t_game *game)
{
	int		i;
	int		j;
	bool	flag;

	i = 0;
	j = 0;
	flag = false;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'O' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				if (flag == true)
					return (false);
				_player_pos(game, i, j, map[i][j]);
				flag = true;
			}
			j++;
		}
		i++;
	}
	return (true);
}

void	_player_cd(t_game *game, int i, int j)
{
	game->player.pos.x = j + 0.5;
	game->player.pos.y = i + 0.5;
}

void	_player_pos(t_game *game, int i, int j, char c)
{
	_player_cd(game, i, j);
	if (c == 'N')
	{
		game->player.dir.y = -1;
		game->player.dir.x = 0;
		game->player.plane.x = 0.66;
	}
	else if (c == 'S')
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
		game->player.plane.x = -0.66;
	}
	else if (c == 'E')
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
		game->player.plane.y = 0.66;
	}
	else if (c == 'O')
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
		game->player.plane.y = 0.66;
	}
}

bool	_check_closed_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	if (!_check_top_bot(game->data.map[i]))
		return (false);
	while (game->data.map[++i])
	{
		j = 0;
		while (game->data.map[i][j])
		{
			if (game->data.map[i][j] == '0' || game->data.map[i][j] == 'N'
				|| game->data.map[i][j] == 'S' || game->data.map[i][j] == 'O'
				|| game->data.map[i][j] == 'E')
			{
				if (!_there_is_walls(game->data.map, i, j))
					return (false);
			}
			j++;
		}
	}
	if (!_check_top_bot(game->data.map[i - 1]))
		return (false);
	return (true);
}
