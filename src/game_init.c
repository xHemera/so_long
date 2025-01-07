/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:19:09 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/06 14:32:55 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_content(t_content *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->space = '0';
	content->collect = 'C';
}

void	set_sprite(t_data *data)
{
	data->sprite.height = 80;
	data->sprite.width = 80;
	data->sprite.floor = "./assets/floor.xpm";
	data->sprite.wall = "./assets/wall.xpm";
	// data->sprite.collect = "./rsrc/collect.xpm";
	data->sprite.player = "./assets/mage.xpm";
	// data->sprite.exit = "./rsrc/exit_texture.xpm";
	data->sprite.sprite_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.wall, &(data->sprite.width), &(data->sprite.height));
	data->sprite.sprite_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.floor, &(data->sprite.width), &(data->sprite.height));
	data->sprite.sprite_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.player, &(data->sprite.width), &(data->sprite.height));
}
