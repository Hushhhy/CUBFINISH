/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:07:23 by acarpent          #+#    #+#             */
/*   Updated: 2025/02/05 16:29:41 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_init_mlx(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		exit(_error_msg_free("mlx", ERR_MLX_INIT, 1, game));
	get_textures(game);
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->mlx.win_ptr)
		exit(_error_msg_free("mlx", ERR_MLX_WIN, 1, game));
	game->mlx.img_ptr = mlx_new_image(game->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img_ptr,
			&game->mlx.bpp, &game->mlx.size_line,
			&game->mlx.endian);
	mlx_hook(game->mlx.win_ptr, 2, 1L << 0, _key_press, game);
	mlx_hook(game->mlx.win_ptr, 3, 1L << 1, _key_release, game);
	mlx_hook(game->mlx.win_ptr, 17, 0, _close_game, game);
	mlx_loop_hook(game->mlx.mlx_ptr, _game, game);
	mlx_loop(game->mlx.mlx_ptr);
	return ;
}
