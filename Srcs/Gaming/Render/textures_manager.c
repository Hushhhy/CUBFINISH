/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:25:45 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/30 15:20:18 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	upload_texture(t_game *game, t_img *text, char *path)
{
	if (!text)
		return (1);
	if (!path)
		return (1);
	if (!game->mlx.mlx_ptr)
		return (1);
	text->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path,
			&text->width, &text->height);
	if (!text->img)
		return (1);
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel,
			&text->line_length, &text->endian);
	if (!text->addr)
	{
		mlx_destroy_image(game->mlx.mlx_ptr, text->img);
		text->img = NULL;
		return (1);
	}
	return (0);
}

int	load_textures(t_game *game)
{
	if (upload_texture(game, &game->text[0], game->data.no_texture))
		return (1);
	if (upload_texture(game, &game->text[1], game->data.so_texture))
		return (1);
	if (upload_texture(game, &game->text[2], game->data.we_texture))
		return (1);
	if (upload_texture(game, &game->text[3], game->data.ea_texture))
		return (1);
	return (0);
}

void	get_textures(t_game *game)
{
	if (load_textures(game))
	{
		_error_msg("Textures", ERR_TEXTURES, 1);
		_close_game(game);
	}	
}

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx.mlx_ptr, game->text[i].img);
		i++;
	}
}
