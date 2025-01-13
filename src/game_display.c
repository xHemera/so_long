/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:52:56 by hemera            #+#    #+#             */
/*   Updated: 2025/01/13 11:53:16 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int print_map(t_data *data, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[i])
		{
			if (line[i] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.sprite_wall, (i * TILE_SIZE), (j * TILE_SIZE));
			else if (line[i] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.sprite_floor, (i * TILE_SIZE), (j * TILE_SIZE));
			else if (line[i] == 'p')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.sprite_floor, (i * TILE_SIZE), (j * TILE_SIZE));
				init_player(*data, i, j);
			}
			i++;
		}
		i = 0;
		line = get_next_line(fd);
		j++;
	}
	return (0);
}

int print_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.sprite_player, (data->position.x * TILE_SIZE), (data->position.y * TILE_SIZE));
	return (0);
}
