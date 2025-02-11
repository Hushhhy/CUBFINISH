/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:14:37 by acarpent          #+#    #+#             */
/*   Updated: 2024/07/10 15:12:24 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free2(char *buffer, char *stash)
{
	int		i;
	int		j;
	char	*res;

	if (!stash)
	{
		stash = malloc(sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buffer)
		return (free(stash), NULL);
	res = malloc(sizeof(char) * ((ft_strlen(buffer) + ft_strlen(stash)) + 1));
	if (!res)
		return (NULL);
	j = 0;
	i = -1;
	while (stash[++i])
		res[i] = stash[i];
	while (buffer[j])
		res[i++] = buffer[j++];
	res[i] = '\0';
	free(stash);
	return (res);
}
