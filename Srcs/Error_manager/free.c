/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:04:23 by codespace         #+#    #+#             */
/*   Updated: 2025/02/05 19:01:37 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_free_colors(char *ceiling, char *floor)
{
	if (ceiling)
	{
		free(ceiling);
		ceiling = NULL;
	}
	if (floor)
	{
		free(floor);
		floor = NULL;
	}
}

void	_free_texture(char *no, char *so, char *ea, char *we)
{
	if (no)
	{
		free(no);
		no = NULL;
	}
	if (so)
	{
		free(so);
		so = NULL;
	}
	if (ea)
	{
		free(ea);
		ea = NULL;
	}
	if (we)
	{
		free(we);
		we = NULL;
	}
}
