/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:26:57 by tobesnar          #+#    #+#             */
/*   Updated: 2025/04/10 16:39:19 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	error_message(t_data *data, int player_count,
			int exit_count, int collectible_count)
{
	if (player_count != 1)
	{
		perror("Error\nnombre de joueurs incorrect.\n");
		end(data);
		exit(0);
	}
	if (exit_count != 1)
	{
		perror("Error\npas de sortie.\n");
		end(data);
		exit(0);
	}
	if (collectible_count < 1)
	{
		perror("Error\npas de collectible.\n");
		end(data);
		exit(0);
	}
}

void	count_map_elements(t_data *data,
	int *player_count, int *exit_count, int *collectible_count)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			tile = data->map_content[y][x];
			if (tile == 'P')
				(*player_count)++;
			else if (tile == 'E')
				(*exit_count)++;
			else if (tile == 'C')
				(*collectible_count)++;
			x++;
		}
		y++;
	}
}

void	validate_map(t_data *data)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	count_map_elements(data, &player_count, &exit_count, &collectible_count);
	error_message(data, player_count, exit_count, collectible_count);
}

void	check_reachability(t_data *data)
{
	data->clone = clone_map(data);
	flood_fill(data, data->pos.x,
		data->pos.y);
	check_unreachable_collectibles(data, data->map_content,
		data->rows, data->cols);
	check_unreachable_exit(data, data->map_content,
		data->rows, data->cols);
	free_clone(data, data->rows);
}

void	validate_playable_map(t_data *data)
{
	validate_walls_and_rectangle(data);
	validate_map(data);
	check_reachability(data);
}
