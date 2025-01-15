/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:52:56 by hemera            #+#    #+#             */
/*   Updated: 2025/01/15 15:07:03 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_img(t_data *data, int x, int y, char z)
{
	if (z == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite.img_wall, (x * 80), (y * 80));
	else if (z == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite.img_floor, (x * 80), (y * 80));
	return (0);
}

int	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_content[j])
	{
		i = 0;
		while (data->map_content[j][i])
		{
			if (data->map_content[j][i] == 'p')
				init_player(data, i, j);
			else
				print_img(data, i, j, data->map_content[j][i]);
			i++;
		}
		j++;
	}
	return (0);
}

int	print_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprite.img_player, (data->pos.x * 80), (data->pos.y * 80));
	return (0);
}
