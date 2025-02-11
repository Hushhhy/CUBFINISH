/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:01:04 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/11 15:23:04 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	_getfile(t_game *game, char *file)
{
	int		lc;

	lc = 0;
	game->data.fd = open(file, O_RDONLY);
	if (game->data.fd < 0)
		return (0);
	lc = _get_size(game);
	close(game->data.fd);
	game->data.fd = open(file, O_RDONLY);
	game->data.file = _gnl_in_file(game, lc);
	if (!game->data.file)
		return (0);
	close(game->data.fd);
	return (1);
}

int	_get_size(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(game->data.fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(game->data.fd);
	}
	return (i);
}

char	**_gnl_in_file(t_game *game, int lc)
{
	char	**infile;
	char	*line;
	int		i;

	i = 0;
	infile = malloc(sizeof(char *) * (lc + 1));
	if (!infile)
		return (NULL);
	line = get_next_line(game->data.fd);
	while (line)
	{
		infile[i] = line;
		line = get_next_line(game->data.fd);
		i++;
	}
	infile[i] = NULL;
	return (infile);
}
