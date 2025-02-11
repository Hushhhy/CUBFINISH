/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_displayer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:53 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/31 14:50:26 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_texture_color(t_img *text, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= text->width || y < 0 || y >= text->height)
		return (0);
	dst = text->addr + (y * text->line_length + x * (text->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

static void	init_line_params(t_draw_line *params, double *step, double *tex_pos)
{
	double	line_height;

	line_height = params->end - params->start;
	*step = params->texture->height / line_height;
	*tex_pos = 0;
	if (params->start < 0)
		*tex_pos = -params->start * (*step);
}

void	draw_textured_line(t_game *game, t_draw_line params)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;

	init_line_params(&params, &step, &tex_pos);
	if (params.start < 0)
		params.start = 0;
	if (params.end >= WIN_HEIGHT)
		params.end = WIN_HEIGHT - 1;
	y = params.start;
	while (y <= params.end)
	{
		tex_y = (int)tex_pos & (params.texture->height - 1);
		tex_pos += step;
		color = get_texture_color(params.texture, params.tex_x, tex_y);
		my_mlx_pixel_put(game, params.x, y, color);
		y++;
	}
}

void	draw_walls(int x, t_ray ray, t_game *game)
{
	t_draw_line	params;

	params.texture = select_texture(ray, game);
	params.tex_x = (int)(ray.wall_x * (double)TEXTURE_WIDTH);
	if (ray.side == 0 && ray.raydir.x > 0)
		params.tex_x = TEXTURE_WIDTH - params.tex_x - 1;
	if (ray.side == 1 && ray.raydir.y < 0)
		params.tex_x = TEXTURE_WIDTH - params.tex_x - 1;
	params.x = x;
	params.start = ray.start;
	params.end = ray.end;
	draw_textured_line(game, params);
}
