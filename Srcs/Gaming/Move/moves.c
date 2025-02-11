/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:25:31 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/30 15:18:37 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_game *game, double move_speed)
{
	if (game->key.key[W])
	{
		if (!game->data.map_int[(int)(game->player.pos.y + game->player.dir.y
				* (move_speed))][(int)game->player.pos.x])
			game->player.pos.y += game->player.dir.y * move_speed;
		if (!game->data.map_int[(int)game->player.pos.y][(int)
			(game->player.pos.x + game->player.dir.x * (move_speed))])
			game->player.pos.x += game->player.dir.x * move_speed;
	}
}

void	move_backward(t_game *game, double move_speed)
{
	if (game->key.key[S])
	{
		if (!game->data.map_int[(int)(game->player.pos.y - game->player.dir.y
				* (move_speed))][(int)game->player.pos.x])
			game->player.pos.y -= game->player.dir.y * move_speed;
		if (!game->data.map_int[(int)game->player.pos.y][(int)
			(game->player.pos.x - game->player.dir.x * (move_speed))])
			game->player.pos.x -= game->player.dir.x * move_speed;
	}
}

void	move_left(t_game *game, double move_speed)
{
	if (game->key.key[A])
	{
		if (!game->data.map_int[(int)(game->player.pos.y - game->player.dir.x
				* (move_speed))][(int)game->player.pos.x])
			game->player.pos.y -= game->player.dir.x * move_speed;
		if (!game->data.map_int[(int)game->player.pos.y][(int)
			(game->player.pos.x + game->player.dir.y * (move_speed))])
			game->player.pos.x += game->player.dir.y * move_speed;
	}
}

void	move_right(t_game *game, double move_speed)
{
	if (game->key.key[D])
	{
		if (!game->data.map_int[(int)(game->player.pos.y + game->player.dir.x
				* (move_speed))][(int)game->player.pos.x])
			game->player.pos.y += game->player.dir.x * move_speed;
		if (!game->data.map_int[(int)game->player.pos.y][(int)
			(game->player.pos.x - game->player.dir.y * (move_speed))])
			game->player.pos.x -= game->player.dir.y * move_speed;
	}
}

void	_handle_move(t_game *game)
{
	double	move_speed;

	move_speed = MOVE_SPEED;
	move_forward(game, move_speed);
	move_backward(game, move_speed);
	move_left(game, move_speed);
	move_right(game, move_speed);
	rotate_left(game);
	rotate_right(game);
}
