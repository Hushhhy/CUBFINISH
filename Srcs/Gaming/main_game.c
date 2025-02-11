/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:30:33 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/30 15:16:39 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	_game(t_game *game)
{
	_handle_move(game);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_ptr);
	game->mlx.img_ptr = mlx_new_image(game->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!game->mlx.img_ptr)
		return (-1);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img_ptr,
			&game->mlx.bpp, &game->mlx.size_line,
			&game->mlx.endian);
	if (!game->mlx.addr)
		return (-1);
	mlx_put_image_to_window(game->mlx.mlx_ptr,
		game->mlx.win_ptr, game->mlx.img_ptr, 0, 0);
	_render(game);
	return (0);
}
