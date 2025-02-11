/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:53:40 by acarpent          #+#    #+#             */
/*   Updated: 2025/02/05 19:04:01 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	*convert_line(char *s)
{
	int	*line;
	int	i;

	i = 0;
	line = malloc(sizeof(int) * ft_strlen(s));
	if (!line)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '1')
			line[i] = 1;
		else
			line[i] = 0;
		i++;
	}
	return (line);
}

int	**_convert_map(t_game *game)
{
	int	i;
	int	**map;

	i = 0;
	game->data.map_height = _get_map_height(game->data.map);
	map = malloc(sizeof(int *) * game->data.map_height);
	if (!map)
		return (NULL);
	while (game->data.map[i])
	{
		map[i] = convert_line(game->data.map[i]);
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static void	change_void_in_wall(t_game *game, int max_len, int i)
{
	int	j;

	j = 0;
	while (j < max_len)
	{
		if (game->data.map[i][j] == ' ')
			game->data.map[i][j] = '1';
		j++;
	}
}

void	_map_realloc(t_game *game)
{
	int		len;
	int		i;

	i = 0;
	game->data.map_width = _get_map_width(game->data.map) - 1;
	while (game->data.map[i])
	{
		len = ft_strlen(game->data.map[i]);
		if (game->data.map[i][len - 1] == '\n')
			len--;
		_smaller_line(game, len, i);
		change_void_in_wall(game, game->data.map_width, i);
		i++;
	}
}

void	_smaller_line(t_game *game, int len, int i)
{
	char	*new;

	if (len < game->data.map_width)
	{
		new = malloc(game->data.map_width + 2);
		if (!new)
			return ;
		ft_strncpy(new, game->data.map[i], len);
		ft_memset(new + len, '1', game->data.map_width - len);
		new[game->data.map_width] = '\0';
		if (game->data.map[i][len] == '\n')
			new[game->data.map_width] = '\n';
		new[game->data.map_width + 1] = '\0';
		free(game->data.map[i]);
		game->data.map[i] = new;
	}
}
