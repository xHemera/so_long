/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:40:03 by tobesnar          #+#    #+#             */
/*   Updated: 2025/04/10 16:42:20 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_rectangle(t_data *data)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < data->rows)
	{
		if ((int)ft_strlen(data->map_content[y]) != data->cols)
		{
			perror("Error\nMap non rectangulaire\n");
			end(data);
			exit(0);
		}
		y++;
	}
}

void	validate_top_and_bottom_walls(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->cols)
	{
		if (data->map_content[0][x] != '1'
			|| data->map_content[data->rows - 1][x] != '1')
		{
			perror("Error\nMurs non completes\n");
			end(data);
			exit(0);
		}
		x++;
	}
}

void	validate_side_walls(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->rows)
	{
		if (data->map_content[y][0] != '1'
			|| data->map_content[y][data->cols - 1] != '1')
		{
			perror("Error\nMurs non completes\n");
			end(data);
			exit(0);
		}
		y++;
	}
}

void	validate_walls_and_rectangle(t_data *data)
{
	validate_rectangle(data);
	validate_top_and_bottom_walls(data);
	validate_side_walls(data);
}
