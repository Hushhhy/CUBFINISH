/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:12:43 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/28 16:55:10 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*_new_alloc(int start, char *line)
{
	int		i;
	int		end;
	char	*tmp;

	i = start;
	while (line[i] && (line[i] != ' ' && line[i] != '\t'))
		i++;
	end = i - start;
	tmp = malloc(sizeof(char) * (end + 1));
	if (!tmp)
		return (NULL);
	return (tmp);
}
