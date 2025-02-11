/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:40:38 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/28 17:02:44 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return (_error_msg_free("Detail", ERR_PIXEL, 1, game));
	dst = game->mlx.addr + (y * game->mlx.size_line + x * (game->mlx.bpp / 8));
	*(unsigned int *)dst = color;
	return (0);
}

// int	get_texture_color(t_img *text, int x, int y)
// {
// 	char	*dst;

// 	if (x < 0 || x >= TEXTURE_WIDTH || y < 0 || y >= TEXTURE_HEIGHT)
// 		return (0);
// 	dst = text->addr + (y * text->line_length + x * (text->bits_per_pixel / 8));
// 	return (*(unsigned int *)dst);
// }

void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				my_mlx_pixel_put(game, x, y, game->data.ceiling_rgb);
			else
				my_mlx_pixel_put(game, x, y, game->data.floor_rgb);
			x++;
		}
		y++;
	}
}
