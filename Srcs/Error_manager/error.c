/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:04:10 by codespace         #+#    #+#             */
/*   Updated: 2025/02/05 18:56:38 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	_error_msg_free(char *det, char *str, int code, t_game *game)
{
	ft_putstr_fd(RED "Error\n", 2);
	if (det)
		ft_putstr_fd(det, 2);
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n" RESET, 2);
	_close_game(game);
	return (code);
}

int	_error_msg(char *det, char *str, int code)
{
	ft_putstr_fd(RED "Error\n", 2);
	if (det)
		ft_putstr_fd(det, 2);
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n" RESET, 2);
	return (code);
}

int	_err_msg_val(int detail, char *str, int code, t_game *game)
{
	ft_putstr_fd(RED "Error\n", 2);
	ft_putnbr_fd(detail, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n" RESET, 2);
	_close_game(game);
	return (code);
}
