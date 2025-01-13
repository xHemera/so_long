/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:19:09 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/13 15:46:29 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_sprite(t_data *data)
{
	data->sprite.height = 80;
	data->sprite.width = 80;
	data->sprite.floor = "./assets/floor.xpm";
	data->sprite.wall = "./assets/wall.xpm";
	data->sprite.player = "./assets/mage.xpm";
	data->sprite.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.wall, &(data->sprite.width), &(data->sprite.height));
	data->sprite.img_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.floor, &(data->sprite.width), &(data->sprite.height));
	data->sprite.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.player, &(data->sprite.width), &(data->sprite.height));
}

int	init_player(t_data *data, int x, int y)
{
	data->pos.x = x;
	data->pos.y = y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprite.img_player, (x * 80), (y * 80));
	return (0);
}
