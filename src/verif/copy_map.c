/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:57:13 by tobesnar          #+#    #+#             */
/*   Updated: 2025/04/10 15:59:06 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/verify_map.h"
#include <stdlib.h>

static int map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char **copy_map(char **map)
{
	int		i;
	int		height;
	char	**copy;
	int		j;

	height = map_height(map);
	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
			j++;
		copy[i] = (char *)malloc(sizeof(char) * (j + 1));
		if (!copy[i])
			return (NULL);
		j = 0;
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
