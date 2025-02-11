/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:13:33 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/30 15:17:32 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ADD Key to move and exit game
// CF mon so_long

int	_key_press(int key, t_game *game)
{
	if (key < 203)
		game->key.key[key] = 1;
	if (key == LEFT)
		game->key.left_pressed = true;
	if (key == RIGHT)
		game->key.right_pressed = true;
	if (key == ESC)
		_close_game(game);
	return (0);
}

int	_key_release(int key, t_game *game)
{
	if (key < 203)
		game->key.key[key] = 0;
	if (key == LEFT)
		game->key.left_pressed = false;
	if (key == RIGHT)
		game->key.right_pressed = false;
	return (0);
}

void	rotate_left(t_game *game)
{
	double	oldir;
	double	old_planex;
	double	rot_speed;

	rot_speed = ROT_SPEED;
	if (game->key.left_pressed)
	{
		oldir = game->player.dir.x;
		game->player.dir.x = game->player.dir.x * cos(-rot_speed)
			- game->player.dir.y * sin(-rot_speed);
		game->player.dir.y = oldir * sin(-rot_speed) + game->player.dir.y
			* cos(-rot_speed);
		old_planex = game->player.plane.x;
		game->player.plane.x = game->player.plane.x * cos(-rot_speed)
			- game->player.plane.y * sin(-rot_speed);
		game->player.plane.y = old_planex
			* sin(-rot_speed) + game->player.plane.y
			* cos(-rot_speed);
	}
}

void	rotate_right(t_game *game)
{
	double	oldir;
	double	rot_speed;
	double	old_planex;

	rot_speed = ROT_SPEED;
	if (game->key.right_pressed)
	{
		oldir = game->player.dir.x;
		game->player.dir.x = game->player.dir.x * cos(rot_speed)
			- game->player.dir.y * sin(rot_speed);
		game->player.dir.y = oldir * sin(rot_speed) + game->player.dir.y
			* cos(rot_speed);
		old_planex = game->player.plane.x;
		game->player.plane.x = game->player.plane.x * cos(rot_speed)
			- game->player.plane.y * sin(rot_speed);
		game->player.plane.y = old_planex
			* sin(rot_speed) + game->player.plane.y
			* cos(rot_speed);
	}
}
