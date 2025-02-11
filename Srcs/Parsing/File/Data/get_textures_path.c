/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:03:24 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/30 16:28:11 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*extract_texture_path(char *line, int offset, t_game *game)
{
	int		i;
	int		j;
	char	*texture_path;

	i = offset;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	_point_check(game, line);
	_check_texname(line, game);
	texture_path = _new_alloc(i, line);
	while (line[i] && (line[i] != ' ' && line[i] != '\t'))
	{
		if (line[i] == '\n')
			break ;
		texture_path[j++] = line[i++];
	}
	texture_path[j] = '\0';
	return (texture_path);
}

void	_north_check(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (!game->data.no_texture)
			game->data.no_texture = extract_texture_path(line, 3, game);
		else
			exit(_error_msg_free("Detail", ERR_NORTH, 1, game));
	}
}

void	_south_check(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "SO ", 3))
	{
		if (!game->data.so_texture)
			game->data.so_texture = extract_texture_path(line, 3, game);
		else
			exit(_error_msg_free("Detail", ERR_SOUTH, 1, game));
	}
}

void	_east_check(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (!game->data.ea_texture)
			game->data.ea_texture = extract_texture_path(line, 3, game);
		else
			exit(_error_msg_free("Detail", ERR_EAST, 1, game));
	}
}

void	_west_check(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "WE ", 3))
	{
		if (!game->data.we_texture)
			game->data.we_texture = extract_texture_path(line, 3, game);
		else
			exit(_error_msg_free("Detail", ERR_WEST, 1, game));
	}
}
