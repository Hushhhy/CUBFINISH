/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:48:48 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/30 15:19:24 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_wall_x(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
		ray->wall_x = game->player.pos.y + ray->perp_walldist * ray->raydir.y;
	else
		ray->wall_x = game->player.pos.x + ray->perp_walldist * ray->raydir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	init_ray_delta(t_ray *ray, t_game *game)
{
	ray->mapx = (int)game->player.pos.x;
	ray->mapy = (int)game->player.pos.y;
	if (ray->raydir.y == 0)
		ray->deltadist.x = 1e30;
	else
		ray->deltadist.x = fabs(1 / ray->raydir.x);
	if (ray->raydir.x == 0)
		ray->deltadist.y = 1e30;
	else
		ray->deltadist.y = fabs(1 / ray->raydir.y);
}

void	_calculate_step(t_game *game, t_ray *ray)
{
	init_ray_delta(ray, game);
	if (ray->raydir.x < 0)
	{
		ray->stepx = -1;
		ray->sidedist.x = (game->player.pos.x - ray->mapx) * ray->deltadist.x;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedist.x = (ray->mapx + 1.0 - game->player.pos.x)
			* ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->stepy = -1;
		ray->sidedist.y = (game->player.pos.y - ray->mapy) * ray->deltadist.y;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedist.y = (ray->mapy + 1.0 - game->player.pos.y)
			* ray->deltadist.y;
	}
}

void	calcul_ray(t_game *game, t_ray *ray, int x)
{
	double	camera;

	camera = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydir.x = game->player.dir.x + game->player.plane.x * camera;
	ray->raydir.y = game->player.dir.y + game->player.plane.y * camera;
}

void	dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (ray->mapx >= 0 && ray->mapx < game->data.map_width
			&& ray->mapy >= 0 && ray->mapy < game->data.map_height
			&& game->data.map_int[ray->mapy][ray->mapx] == 1)
		{
			hit = 1;
			break ;
		}
	}
}
