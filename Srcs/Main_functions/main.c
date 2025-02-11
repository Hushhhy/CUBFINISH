/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:22:44 by acarpent          #+#    #+#             */
/*   Updated: 2025/02/05 16:31:01 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	macro_check(void)
{
	if (WIN_HEIGHT > 1440 || WIN_WIDTH > 2560
		|| WIN_HEIGHT < 768 || WIN_WIDTH < 1366)
		exit(_error_msg("RESOLUTION", "Bad resolution", 0));
	if (MOVE_SPEED > 0.5 || MOVE_SPEED < 0.01)
		exit(_error_msg("MOVEMENT", "Bad movement speed", 0));
	if (ROT_SPEED > 0.5 || ROT_SPEED < 0.01)
		exit(_error_msg("MOVEMENT", "Bad rotation speed", 0));
}

int	main(int ac, char **av)
{
	t_game	game;

	macro_check();
	ft_memset(&game, 0, sizeof(t_game));
	if (ac != 2)
		return (_error_msg("Usage", ERR_ARG, 1));
	_checkname(av[1]);
	if (!_getfile(&game, av[1]))
		return (_error_msg("Detail", ERR_GET_FILE, 1));
	_parse_file(&game);
	_init_mlx(&game);
	return (0);
}
