/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:00:26 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/13 15:18:46 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_checkname(char *name)
{
	char	*ext;

	ext = ft_strrchr(name, '.');
	if (!ext || ft_strncmp(ext, ".cub\0", 5))
		exit(_error_msg("Detail", ERR_NAME, 1));
	if (_is_directory(name))
		exit(_error_msg("Detail", ERR_IS_DIR, 1));
}

bool	_is_directory(char *name)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(name, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}
