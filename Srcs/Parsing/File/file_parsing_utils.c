/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:13:24 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/13 13:04:36 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_verify(t_game *game, int i)
{
	int		start;
	char	*line;
	int		last;

	line = NULL;
	start = _emptylines(game, i) - 1;
	last = -1;
	while (game->data.file[start++])
	{
		line = game->data.file[start];
		if (!_line_empty(line))
			last = start;
		else if (last != -1)
			break ;
		if (_is_invalid(line, game))
			exit(_error_msg_free("Error", ERR_CHAR, 1, game));
	}
	_after_map(game, last);
	if (i == start || game->player.p_count != 1 || last == -1)
		exit(_error_msg_free("Detail", ERR_FORMAT, 1, game));
}

int	_emptylines(t_game *game, int start)
{
	int	lc;
	int	i;

	lc = start + 1;
	while (game->data.file[lc])
	{
		i = 0;
		while (game->data.file[lc][i] && (game->data.file[lc][i] == ' '
			|| game->data.file[lc][i] == '\t'
			|| (game->data.file[lc][i] == '\n')))
			i++;
		if (game->data.file[lc][i] != '\0' && game->data.file[lc][i] != '1')
			exit(_error_msg_free("Detail", ERR_FORMAT, 1, game));
		else if (game->data.file[lc][i] == '1')
			break ;
		lc++;
	}
	return (lc);
}

int	_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
		i++;
	if (line[i] == '\0')
		return (1);
	else
		return (0);
}

int	_is_invalid(char *line, t_game *game)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'E' || line[i] == 'W'
			|| line[i] == 'S')
			game->player.p_count++;
		else if (line[i] != ' ' && line[i] != '\t' && line[i] != '0'
			&& line[i] != '1' && line[i] != '\n')
			return (1);
		flag++;
		i++;
	}
	return (0);
}

void	_after_map(t_game *game, int last)
{
	int		i;
	char	*line;

	i = last + 1;
	while (game->data.file[i])
	{
		line = game->data.file[i];
		if (!_line_empty(line))
			exit(_error_msg_free("Detail", ERR_AFTER, 1, game));
		i++;
	}
}
