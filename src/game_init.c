/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:19:09 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/13 11:50:30 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_content(t_content *content)
{
	content->exit = 'e';
	content->player = 'p';
	content->wall = '1';
	content->space = '0';
	content->collect = 'c';
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

int init_player(t_data data, int x, int y)
{
	data.position.x = x;
	data.position.y = y;
	printf("Position du joueur initialisée à X = %i, et Y = %i\n", data.position.x, data.position.y);
	return (0);
}
