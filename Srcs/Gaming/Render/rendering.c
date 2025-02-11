/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:21:03 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/30 15:19:40 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_texture_coords(t_ray ray, t_game *game, double *wall_x,
		int *tex_x)
{
	if (ray.side == 0)
		*wall_x = game->player.pos.y + ray.perp_walldist * ray.raydir.y;
	else
		*wall_x = game->player.pos.x + ray.perp_walldist * ray.raydir.x;
	*wall_x -= floor(*wall_x);
	*tex_x = (int)(*wall_x * TEXTURE_WIDTH);
	if (ray.side == 0 && ray.raydir.x < 0)
		*tex_x = TEXTURE_WIDTH - *tex_x - 1;
	if (ray.side == 1 && ray.raydir.y < 0)
		*tex_x = TEXTURE_WIDTH - *tex_x - 1;
}

t_img	*select_texture(t_ray ray, t_game *game)
{
	if (ray.side == 0)
	{
		if (ray.raydir.x > 0)
			return (&game->text[3]);
		return (&game->text[2]);
	}
	if (ray.raydir.y > 0)
		return (&game->text[1]);
	return (&game->text[0]);
}

double	_calculate_perp_wall_dist(t_game *game, t_ray ray)
{
	if (ray.side == 0)
		return ((ray.mapx - game->player.pos.x + (1 - ray.stepx) / 2)
			/ ray.raydir.x);
	return ((ray.mapy - game->player.pos.y + (1 - ray.stepy) / 2)
		/ ray.raydir.y);
}

void	_render(t_game *game)
{
	int		x;
	t_ray	ray;
	double	wall_height;

	x = 0;
	draw_floor_ceiling(game);
	while (x < WIN_WIDTH)
	{
		calcul_ray(game, &ray, x);
		_calculate_step(game, &ray);
		dda(game, &ray);
		ray.perp_walldist = _calculate_perp_wall_dist(game, ray);
		calculate_wall_x(&ray, game);
		wall_height = WIN_HEIGHT / ray.perp_walldist;
		ray.lineheight = (int)wall_height;
		ray.start = -ray.lineheight / 2 + WIN_HEIGHT / 2;
		ray.end = ray.lineheight / 2 + WIN_HEIGHT / 2;
		draw_walls(x, ray, game);
		x++;
	}
}
