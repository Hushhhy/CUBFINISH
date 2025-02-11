/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:29:04 by acarpent          #+#    #+#             */
/*   Updated: 2025/02/05 19:00:44 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_free_map_int(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->data.map_height)
	{
		free(game->data.map_int[i]);
		i++;
	}
	free(game->data.map_int);
}

static void	_del_texture(t_game *game)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (game->text[i].img)
			mlx_destroy_image(game->mlx.mlx_ptr, game->text[i].img);
		i++;
	}
}

static void	_clear_texture_paths(t_game *game)
{
	if (game->data.no_texture)
		free(game->data.no_texture);
	if (game->data.so_texture)
		free(game->data.so_texture);
	if (game->data.we_texture)
		free(game->data.we_texture);
	if (game->data.ea_texture)
		free(game->data.ea_texture);
}

int	_close_game(t_game *game)
{
	if (game->data.ceiling_color)
		free(game->data.ceiling_color);
	if (game->data.floor_color)
		free(game->data.floor_color);
	if (game->data.file)
		ft_free(game->data.file);
	if (game->data.map)
		ft_free(game->data.map);
	if (game->mlx.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_ptr);
	_clear_texture_paths(game);
	_del_texture(game);
	if (game->data.map_int)
		ft_free_map_int(game);
	if (game->mlx.win_ptr)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	if (game->mlx.mlx_ptr)
		mlx_destroy_display(game->mlx.mlx_ptr);
	if (game->mlx.mlx_ptr)
		free(game->mlx.mlx_ptr);
	exit(0);
}
