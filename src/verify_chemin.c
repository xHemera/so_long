/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_chemin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:22:44 by tobesnar          #+#    #+#             */
/*   Updated: 2025/04/10 16:38:55 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**clone_map(t_data *data)
{
	int		i;

	data->clone = malloc(data->rows * sizeof(char *));
	if (!data->clone)
	{
		perror("Error\nMemory allocation failed for map clone.\n");
		exit(0);
	}
	i = 0;
	while (i < data->rows)
	{
		data->clone[i] = ft_strdup(data->map_content[i]);
		if (!data->clone[i])
		{
			perror("Error\nallocation a echoue.\n");
			while (--i >= 0)
				free(data->clone[i]);
			free(data->clone);
			exit(0);
		}
		i++;
	}
	return (data->clone);
}

void	free_clone(t_data *data, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(data->clone[i]);
		i++;
	}
	free(data->clone);
}

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->cols || y < 0 || y >= data->rows
		|| data->clone[y][x] == '1' || data->clone[y][x] == 'V')
		return ;
	data->clone[y][x] = 'V';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

void	check_unreachable_collectibles(t_data *data,
			char **map, int rows, int cols)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == 'C' && data->clone[y][x] != 'V')
			{
				perror("Error\nCollectible non atteignable.\n");
				free_clone(data, rows);
				end(data);
				exit(0);
			}
			x++;
		}
		y++;
	}
}

void	check_unreachable_exit(t_data *data, char **map,
		int rows, int cols)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == 'E' && data->clone[y][x] != 'V')
			{
				perror("Error\nSortie non atteignable.\n");
				free_clone(data, rows);
				end(data);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}
