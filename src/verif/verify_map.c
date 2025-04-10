/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:54:08 by tobesnar          #+#    #+#             */
/*   Updated: 2025/04/10 15:59:03 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/verify_map.h"
#include <stdlib.h>

static void find_player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int verify_map(char **map)
{
	char	**copy;
	int		x;
	int		y;

	copy = copy_map(map);
	if (!copy)
		return (0);
	find_player_position(copy, &x, &y);
	floodfill(copy, x, y);
	if (!is_path_valid(copy))
	{
		free_map_copy(copy);
		return (0);
	}
	free_map_copy(copy);
	return (1);
}
